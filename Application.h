//
// Created by ParthSchool on 1/4/2020.
//

#ifndef PHYSICS_ENGINE_APPLICATION_H
#define PHYSICS_ENGINE_APPLICATION_H

#include "TransformObject.h"

class Application {

    private:
        std::vector<TransformObject> objects;

    public:
        void init();
        void execute();

        void addObject(TransformObject object);

};


#endif //PHYSICS_ENGINE_APPLICATION_H
