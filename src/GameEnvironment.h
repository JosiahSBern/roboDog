#ifndef GAME_ENVIRONMENT_H
#define GAME_ENVIRONMENT_H

#include "Environment.h"
#include "TrashTurtle.h"
#include "TeleopTurtle.h"
#include "Point.h"
#include <vector>
#include <memory>
#include <mutex>
class GameEnvironment : public Environment {
private:
    std::vector<Point> binPositions;  //Positions of bins
    std::vector<std::shared_ptr<TrashTurtle>> trashTurtles;  //TrashTurtle instances
    std::shared_ptr<TeleopTurtle> teleopTurtle;  
    std::shared_ptr<TrashTurtle> activeFollower; 
    rclcpp::TimerBase::SharedPtr timer_;
    std::mutex updateMutex; 
    
    std::shared_ptr<TrashTurtle> activeFollower;  // Track the current follower
    std::shared_ptr<TeleopTurtle> teleopTurtle;
    

public:
    void updateTrashTurtles();
    ~GameEnvironment();
    GameEnvironment(rclcpp::Node::SharedPtr node, const std::string& turtle_name);
    void drawGame(); 
    void drawWalls(); 
    void drawBins();
    void assignFollower(); 
    void spawnTrashTurtles();
};

#endif  
