#version 330 core

in layout(location = 0) vec3 vertex_position;
in layout(location = 1) vec3 vertex_colour;

out vec3 pass_vertex_colour;

void main()
{
	gl_Position = vec4(position, 1.0f);
	pass_vertex_colour = vertex_colour;
}