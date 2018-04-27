#version 330 core

in layout(location = 0) vec2 vertex_position;
in layout(location = 1) vec3 vertex_colour;

out vec3 pass_vertex_colour;

void main()
{
	gl_Position = vec4(vertex_position.x, vertex_position.y, 0.0f, 1.0f);
	pass_vertex_colour = vertex_colour;
}