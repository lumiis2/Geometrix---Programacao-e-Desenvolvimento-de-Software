#include "State.hpp"
#include "Object.hpp"

State::State() {}

State& State::getInstance() {
    static State instance;
    return instance;
}

size_t State::nextId = 0;

size_t State::add(std::shared_ptr<Object> obj, std::set<size_t> dependencies) {
    size_t id = nextId++;
    objects[id] = obj;
    parents[id].insert(dependencies.begin(), dependencies.end());
    for (auto parent : dependencies)
        children[parent].insert(id);
    return id;
}

void State::clear() {
    nextId = 0;
    objects.clear();
    parents.clear();
    children.clear();
}

void State::remove(size_t id) {
    State::remove(id, id);
}

void State::remove(size_t id, size_t last) {
    for (auto child : children[id])
        remove(child, id);
    for (auto parent : parents[id])
        if (parent != last) children[parent].erase(id);
    objects.erase(id);
    parents.erase(id);
    children.erase(id);
}

std::shared_ptr<Object> State::get(size_t id) {
    if (objects.find(id) == objects.end())
        throw std::runtime_error("Objeto com id " + std::to_string(id) + " não encontrado!");
    return objects[id];
}

std::vector<std::pair<size_t, std::shared_ptr<Object>>> State::getObjects() {
    std::vector<std::pair<size_t, std::shared_ptr<Object>>> objectVector;
    for (auto[id, obj] : objects)
        objectVector.push_back({id, obj});
    return objectVector;
}
