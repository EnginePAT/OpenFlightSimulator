#ifndef SHAPES_H
#define SHAPES_H


#include <Renderer/Mesh/Mesh.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace Crunch
{

class Shape
{
public:
    /*static inline const Mesh Triangle(float x, float y, float base, float height, glm::vec4 color)
    {
        // Do nothing for now
        Mesh mesh();
        return mesh;
    }*/

    static inline const Mesh Quad(glm::vec3 pos, float width, float height, glm::vec4 color)
    {
        float halfX = width / 2.0f;
        float halfY = height / 2.0f;

        Mesh mesh;

        mesh.vertices = {
            -halfX, -halfY, 0.0f,
            halfX, -halfY, 0.0f,
            -halfX, halfY, 0.0f,
            halfX, halfY, 0.0f
        };
        mesh.indices = {
            0, 1, 3,
            0, 3, 2
        };

        // Set the transform of the mesh, indexCount and vertexCount
        mesh.model = glm::translate(mesh.model, pos);
        mesh.indexCount = static_cast<unsigned int>(mesh.indices.size());
        mesh.vertexCount = static_cast<unsigned int>(mesh.vertices.size());

        // Set the mesh color
        mesh.setColor(color);

        mesh.uploadToGpu();
        return mesh;
    }
};

};


#endif      // SHAPES_H
