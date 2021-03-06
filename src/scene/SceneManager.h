//============================================================================
// Name        : SceneManager.h
// Author      : Rian van Gijlswijk
// Description : Keeps track of all objects in the scene and calculates
// 				 collisions between scene objects and rays
//============================================================================

#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include <list>
#include <vector> // the general-purpose vector container
#include "../math/Line2d.h"
#include "../math/Line3d.h"
#include "../tracer/Ray.h"
#include "../tracer/Intersection.h"
#include "Geometry.h"

namespace raytracer {
namespace scene {

	using namespace std;
	using namespace tracer;

	class SceneManager {

		public:
			SceneManager();

			/**
			 * Find which object in the scene intersects with a ray
			 */
			Intersection intersect(Ray &r, Line3d &rayLine);

			/**
			 *  Load celestial and application configuration values
			 */
			void loadStaticEnvironment();

			/**
			 * Add an object to the scene
			 */
			void addToScene(Geometry* obj);

			/**
			 * Remove all objects currently defined in the scene
			 */
			void removeAllFromScene();

			/**
			 * Return a list of all objects in the scene
			 */
			std::vector<Geometry*> getScene();

			/**
			 * Sort all the objects in the scene by altitude for easier lookup
			 */
			void sortScene();

		private:
			/**
			 * Retrieve a list of scene objects which have a possibility of
			 * colliding with the ray. Other objects are discarded.
			 */
			std::vector<Geometry*> getPossibleHits(Ray &r, Line3d & rayLine);
			bool isInvalid(Geometry* g);

			std::vector<Geometry*> _sceneObjectsVector;

			double dh;
			double minH;
			double maxH;
			double R;
			double angularStepSize;
	};

} /* namespace scene */
} /* namespace raytracer */

#endif /* SCENEMANAGER_H_ */
