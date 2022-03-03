#include <Common.h>
#include <Entity.h>
#include <EntityManager.h>

struct PlayerConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V; float S; };
struct EnemyConfig  { int SR, CR, OR, OG, OB, OT, VMIN, VMAX, L, SI; float SMIN, SMAX; };
struct BulletConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V, L; float S; };

class Game
{
    sf::RenderWindow m_window;
    EntityManager    m_entityManager;
    sf::Font         m_font;
    sf::Text         m_text;
    PlayerConfig     m_playerConfig;
    EnemyConfig      m_enemyConfig;
    BulletConfig     m_bulletConfig;
    int              m_score;
    int              m_currentFrame;
    int              m_lastEnemySpawnTime;
    bool             m_paused = false;
    bool             m_running = true;

    ptr<Entity>      m_player;
    void init(const std::string & config); // initialize the game state with a config file path
    void setPaused(bool paused);           // pause the game

    void sMovement();                      // System: entity position / movement update
    void sUserInput();                     // System: user input
    void sLifespan();                      // System: lifespan
    void sRender();                        // System: Render / Drawing
    void sEnemySpawner();                  // System: Enemy Spawner
    void sCollision();                     // System: Collisions
    
    void spawnPlayer();
    void spawnEnemy();

    void spawnSmallEnemies(ptr<Entity> entity);
    void spawnBullet(ptr<Entity> entity, const Vec2 & mousePos);
    void spawnSpecialWeapon(ptr<Entity> entity);


public:

};