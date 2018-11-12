#version 330 core

uniform mat4 mvp;

layout(location = 0) in vec3 vpos_modelspace;

void main()
{
    gl_Position = mvp * vec4(vpos_modelspace, 1.0f);
}
