#include <EntityManager.h>

EntityManager::EntityManager()
{

}

void EntityManager::removeDeadEntities(EntityVector& entityVec)
{
    // TODO: Remove all dead entities from input vector
    // this will be called by the update function
}


ptr<Entity> EntityManager::addEntity(const std::string & tag)
{
    //TODO: Implement this function so that entities are added to the 
    // m_entitiesToAdd vector here, and then added to the proper 
    // locations in the update() function
    
    //Create the entity shared pointer
    auto entity = ptr<Entity>(new Entity(++m_totalEntities, tag));

    m_entitiesToAdd.push_back(entity);

    return entity;

}

const EntityVector & EntityManager::getEntities()
{
    return m_entities;
}

const EntityVector & EntityManager::getEntities(const std::string & tag)
{
    return m_entities;
}

void EntityManager::update()
{
    // TODO: add entities from m_entitiesToAdd to the proper locations
    //     - add them to the vector of all entities
    //     - add them to the vector inside the map, with the tag as a key

    //     -remove dead entities from the vector of all entities
    removeDeadEntities(m_entities);


    //TODO: Remove dead entities from each vector in the entity map
    // C++17 way of iterating through [key, value] pairs in a map
    for(auto& [tag, entityVec] : m_entityMap)
    {    
        removeDeadEntities(entityVec);
    }

    // for(auto& pair : m_entityMap)
    // {
    //     auto& entityVector = m_entityMap[pair.first];    
    //     removeDeadEntities(entityVector);
    // }    

}