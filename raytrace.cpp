/*
Define the basic data structures: Arrays and Linear search

4. Define classes for basic geometric primitives such as spheres, planes, and triangles.
Include methods to test for intersection between a ray and each primitive.
Implement methods to calculate surface normals and material properties for shading.
Build a scene description:

5. Design a scene using your chosen primitives and define their positions, sizes, and materials.
Store the scene information in a data structure (e.g., an array or a scene graph).
Implement ray-object intersection tests:

6. Create methods to calculate the intersection of a ray with each primitive in the scene.
Apply relevant algorithms for each primitive type (e.g., ray-sphere intersection, ray-plane intersection, etc.).
Add support for lighting:

7. Define a class to represent light sources with properties like position, intensity, and color.
Implement shading models (e.g., Phong reflection model) to calculate the color of each pixel in the image.
Use techniques such as diffuse reflection, specular reflection, and shadows.
Implement the raytracing algorithm:

8. Create a loop to iterate over each pixel in the image plane.
For each pixel, generate a ray from the camera through the pixel.
Test for ray-object intersections with the primitives in the scene.
Calculate the color of the closest intersection point and assign it to the corresponding pixel.
Add anti-aliasing and other effects:

9. Implement techniques such as super-sampling or adaptive sampling to reduce aliasing.
Consider adding effects like reflections, refractions, transparency, and texture mapping.
Optimize the performance:

10. Identify and address performance bottlenecks in your code.
Use techniques like bounding volume hierarchies (BVH) to speed up ray-object intersection tests.
Consider parallelization using multi-threading or GPU acceleration.
Output and display the rendered image:

11. Write the rendered pixel colors to an image file format like BMP or PNG.
Implement functionality to display the final image using a graphics library or viewer.
Test and debug your program:

12. Create test scenes with known results to verify correctness.
Debug any issues or unexpected behavior in your program.
Optimize parameters, algorithms, or data structures as necessary.
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include "vector3.h"

class Ray{
        public:
            Vector3 origin;
            Vector3 direction;

        Ray(const Vector3& origin, const Vector3& direction) 
            : origin(origin), direction(direction) {}

        Vector3 pointAtParameter(float turrip) {
            return origin + (direction * turrip);
        }
    };

    class Sphere{
        public:
        Vector3 center;
        float radius;

        Sphere(const Vector3& center, float radius) 
            : center(center), radius(radius) {}
            
        bool intersect(const Ray& ray) const {
            Vector3 oc = ray.origin - center;
            float a = ray.direction.dot(ray.direction);
            float b = 2.0f * oc.dot(ray.direction);
            float c = oc.dot(oc) - radius * radius;
            float discriminant = b * b - 4.0f * a * c;
            return (discriminant >= 0);
        }
    };

    class Plane {
        public:
            Vector3 normal;
            float distance;

        Plane(const Vector3& normal, float distance)
            : normal(normal), distance(distance) {}
        
        bool intersect(const Ray& ray) const {
            float denom = normal.dot(ray.direction);

            Vector3 rayToPlane = ray.origin - normal * distance;
            float t = rayToPlane.dot(ray.direction)/denom;

            return (t >= 0);
        }
    };

    class Triangle {
        public:
            Vector3 v1, v2, v3;
            
            Triangle(const Vector3& v1, const Vector3& v2, const Vector3& v3)
                : v1(v1), v2(v2), v3(v3) {}
            
            Vector3 calculateSurfaceNormal() const {
                Vector3 U = v2 - v1;
                Vector3 V = v3 - v1;

                Vector3 normal = U.cross(V);
                normal.normalize();
                return normal;
            }
    };

int main(){
    Vector3 origin(0, 0, 0);
    Vector3 direction(1, 0, 0);

    Ray ray(origin, direction);

    Vector3 point = ray.pointAtParameter(1.0f);

    std::cout << "Point on the ray: (" << point.x << ", " << point.y << ", " << point.z << ")" << std::endl;

    Vector3 sphereCenter(1, 0, 0);
    float sphereRadius = 1.0f;

    Sphere sphere(sphereCenter, sphereRadius);

    bool intersects = sphere.intersect(ray);

    std::cout << "Ray intersects the sphere: " << (intersects ? "Yes" : "No") << std::endl;

    Vector3 planeNormal(1, 0, 0);

    Plane plane(planeNormal, 1);
    bool planeIntersects = plane.intersect(ray);

    std::cout << "Ray intersects the plane: " << (planeIntersects ? "Yes" : "No") << std::endl;

    system("pause"); //dont forget to remove later
    return 0;
}