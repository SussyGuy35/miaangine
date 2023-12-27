#ifndef _MIA_GAME_LOOP_HPP
#define _MIA_GAME_LOOP_HPP

namespace mia 
{
    class GameLoop 
    {
    public:
        GameLoop();
        ~GameLoop();
    
    public:
        void Start();
        void Update();
    };
}

#endif