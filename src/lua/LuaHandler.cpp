#include "LuaHandler.hpp"
#include "State.hpp"
#include "Point.hpp"
#include "Segment.hpp"
#include "Polygon.hpp"
#include "Utils.hpp"
#include "ErrorBox.hpp"

namespace luaWrappers {
    static int pointWrapper(lua_State* L) {
        int n = lua_gettop(L);
        if (n != 2) {
            throw std::runtime_error("Número incorreto de argumentos!");
            luaL_error(L, "Número incorreto de argumentos!");
            return 0;
        }
        double x = lua_tonumber(L, 1);
        double y = lua_tonumber(L, 2);
        std::shared_ptr<Object> ptr = std::shared_ptr<Object>(new Point(x, y));
        size_t id = State::getInstance().add(ptr , {});
        lua_pushnumber(L, id);
        return 1;
    }

    static int segmentWrapper(lua_State* L) {
        int n = lua_gettop(L);
        if (n != 2) {
            throw std::runtime_error("Número incorreto de argumentos!");
            luaL_error(L, "Número incorreto de argumentos!");
            return 0;
        }
        size_t idP = lua_tonumber(L, 1);
        size_t idQ = lua_tonumber(L, 2);
        std::shared_ptr<Point> p = std::dynamic_pointer_cast<Point>(State::getInstance().get(idP));
        std::shared_ptr<Point> q = std::dynamic_pointer_cast<Point>(State::getInstance().get(idQ));
        std::shared_ptr<Object> ptr = std::shared_ptr<Object>(new Segment(p, q));
        size_t id = State::getInstance().add(ptr , {idP, idQ});
        lua_pushnumber(L, id);
        return 1;
    }

    static int polygonWrapper(lua_State* L) {
        int n = lua_gettop(L);
        if (n != 2) {
            throw std::runtime_error("Número incorreto de argumentos!");
            luaL_error(L, "Tentativa de criar poligono degenerado!");
            return 0;
        }

        std::vector<std::shared_ptr<Point>> points(n);
        std::set<size_t> ids;
        for (int i = 0; i < n; i++) {
            size_t id = lua_tonumber(L, i+1);
            ids.insert(id);
            points[i] = std::dynamic_pointer_cast<Point>(State::getInstance().get(id));
        }

        size_t id = State::getInstance().add(std::shared_ptr<Polygon>(new Polygon(points)), ids);
        lua_pushnumber(L, id);
        return 1;
    }

    static int areaWrapper(lua_State* L) {
        int n = lua_gettop(L);
        if (n != 1) {
            throw std::runtime_error("Número incorreto de argumentos!");
            luaL_error(L, "Número incorreto de argumentos!");
            return 0;
        }

        size_t id = lua_tonumber(L, 1);
        std::shared_ptr<Polygon> p = std::dynamic_pointer_cast<Polygon>(State::getInstance().get(id));

        if (!p) {
            throw std::runtime_error("Não é possível determinar a área.");
        }

        LuaHandler::out += "Area: " + std::to_string(p->area()) + '\n';
    

        return 0;

    }
    
    static int boundingWrapper(lua_State* L) {
        int n = lua_gettop(L);
        
        std::vector<std::shared_ptr<Object>> objects(n);
        std::set<size_t> ids;
        for (int i = 0; i < n; i++) {
            size_t id = lua_tonumber(L, i+1);
            ids.insert(id);
            objects[i] = State::getInstance().get(id);
        }

        size_t id = State::getInstance().add(utils::boundingBox(objects), ids);
        lua_pushnumber(L, id);
        return 1;
    }
    
    static int convexHullWrapper(lua_State* L) {
        int n = lua_gettop(L);
        
        std::vector<std::shared_ptr<Object>> objects(n);
        std::set<size_t> ids;
        for (int i = 0; i < n; i++) {
            size_t id = lua_tonumber(L, i+1);
            ids.insert(id);
            objects[i] = State::getInstance().get(id);
        }

        size_t id = State::getInstance().add(utils::convexHull(objects), ids);
        lua_pushnumber(L, id);
        return 1;
    }
    
    static int minkowskiWrapper(lua_State* L) {
        int n = lua_gettop(L);
        if (n != 2) {
            throw std::runtime_error("Número incorreto de argumentos!");
            luaL_error(L, "Número incorreto de argumentos!");
            return 0;
        }

        size_t idA = lua_tonumber(L, 1);
        size_t idB = lua_tonumber(L, 2);
        std::shared_ptr<Polygon> a = std::dynamic_pointer_cast<Polygon>(State::getInstance().get(idA));
        std::shared_ptr<Polygon> b = std::dynamic_pointer_cast<Polygon>(State::getInstance().get(idB));

        std::shared_ptr<Polygon> sum = std::make_shared<Polygon>(*a + *b);
        std::cout << "dbg\n";
        size_t id = State::getInstance().add(sum, {idA, idB});
        lua_pushnumber(L, id);
        return 1;
    }
}

std::string LuaHandler::out = "";

LuaHandler::LuaHandler() {
    L = luaL_newstate();
    luaL_openlibs(L);
    registerFunction("Point", luaWrappers::pointWrapper);
    registerFunction("Segment", luaWrappers::segmentWrapper);
    registerFunction("Polygon", luaWrappers::polygonWrapper);
    registerFunction("Area", luaWrappers::areaWrapper);
    registerFunction("BoundingBox", luaWrappers::boundingWrapper);
    registerFunction("ConvexHull", luaWrappers::convexHullWrapper);
    registerFunction("Minkowski", luaWrappers::minkowskiWrapper);
}

LuaHandler::~LuaHandler() {
    lua_close(L);
}

void LuaHandler::registerFunction(std::string name, lua_CFunction function) {
    lua_register(L, name.c_str(), function);
}

void LuaHandler::run(std::string code) {
    LuaHandler::out.clear();
    luaL_dostring(L, code.c_str());
}
