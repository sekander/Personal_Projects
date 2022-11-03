#include "entity.h"


class sprite;
class pc : public Entity 
{

public:
    pc(std::shared_ptr<b2World> world);

    void LoadSprite(
                                std::string fileName,
                                std::string key, 
								bool i_am_a_sprite_sheet, 
								bool change_frame, 
								const unsigned int &x_frame, 
								const unsigned int &y_frame,
								const float &incrementer,
		            			glm::vec2 position, 
		            			glm::vec2 size , 
		            			float rotate , 
		            			glm::vec3 color ,
		            			glm::vec2 m_frames );


    void Load(bool, bool );

    std::shared_ptr<sprite> return_sprite(){return m_sprite; }


private:
    std::shared_ptr<sprite> m_sprite;


};