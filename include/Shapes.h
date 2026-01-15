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
            // x, y, u, v
            -halfX, -halfY, 0.0f, 0.0f, 0.0f,
            halfX, -halfY, 0.0f, 1.0f, 0.0f,
            -halfX, halfY, 0.0f, 0.0f, 1.0f,
            halfX, halfY, 0.0f, 1.0f, 1.0f
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

    static inline const Mesh Cube(glm::vec3 pos, float width, float height, float depth, glm::vec4 color)
    {
        float halfX = width / 2.0f;
        float halfY = height / 2.0f;
        float halfZ = depth / 2.0f;

        Mesh mesh;

        mesh.vertices = {
            // Front face (z = +halfZ)
            -halfX, -halfY,  halfZ, 0.0f, 0.0f,
            halfX, -halfY,  halfZ, 1.0f, 0.0f,
            halfX,  halfY,  halfZ, 1.0f, 1.0f,
            -halfX,  halfY,  halfZ, 0.0f, 1.0f,

            // Back face (z = -halfZ)
            -halfX, -halfY, -halfZ, 1.0f, 0.0f,
            -halfX,  halfY, -halfZ, 1.0f, 1.0f,
            halfX,  halfY, -halfZ, 0.0f, 1.0f,
            halfX, -halfY, -halfZ, 0.0f, 0.0f,

            // Left face (x = -halfX)
            -halfX, -halfY, -halfZ, 0.0f, 0.0f,
            -halfX, -halfY,  halfZ, 1.0f, 0.0f,
            -halfX,  halfY,  halfZ, 1.0f, 1.0f,
            -halfX,  halfY, -halfZ, 0.0f, 1.0f,

            // Right face (x = +halfX)
            halfX, -halfY, -halfZ, 1.0f, 0.0f,
            halfX,  halfY, -halfZ, 1.0f, 1.0f,
            halfX,  halfY,  halfZ, 0.0f, 1.0f,
            halfX, -halfY,  halfZ, 0.0f, 0.0f,

            // Top face (y = +halfY)
            -halfX,  halfY, -halfZ, 0.0f, 0.0f,
            -halfX,  halfY,  halfZ, 0.0f, 1.0f,
            halfX,  halfY,  halfZ, 1.0f, 1.0f,
            halfX,  halfY, -halfZ, 1.0f, 0.0f,

            // Bottom face (y = -halfY)
            -halfX, -halfY, -halfZ, 0.0f, 0.0f,
            halfX, -halfY, -halfZ, 1.0f, 0.0f,
            halfX, -halfY,  halfZ, 1.0f, 1.0f,
            -halfX, -halfY,  halfZ, 0.0f, 1.0f,
        };
        mesh.indices = {
            0, 1, 2, 0, 2, 3,       // Front
            4, 5, 6, 4, 6, 7,       // Back
            8, 9,10, 8,10,11,       // Left
            12,13,14,12,14,15,       // Right
            16,17,18,16,18,19,       // Top
            20,21,22,20,22,23        // Bottom
        };

        mesh.model = glm::translate(mesh.model, pos);
        mesh.vertexCount = static_cast<unsigned int>(mesh.vertices.size());
        mesh.indexCount = static_cast<unsigned int>(mesh.indices.size());

        mesh.setColor(color);

        mesh.uploadToGpu();
        return mesh;
    }
};

};


#endif      // SHAPES_H
