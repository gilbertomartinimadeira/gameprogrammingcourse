#include <Common.h>
#include <Entity.h>

typedef std::vector<ptr<Entity>> EntityVector;
typedef std::map<std::string,EntityVector>   EntityMap;

class EntityManager 
{
    EntityVector m_entities;
    EntityVector m_entitiesToAdd;
    EntityMap    m_entityMap;
    size_t       m_totalEntities = 0;

    void removeDeadEntities(EntityVector& entityVec);

public:
    EntityManager();

    void update();

    ptr<Entity> addEntity(const std::string& tag);
    const EntityVector&     getEntities();
    const EntityVector&     getEntities(const std::string& tag);
};