#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 texture_coord;
layout(location = 3) in float texture_index;

out vec2 v_texture_coord;
out float v_texture_index;
out vec4 v_color;

uniform mat4 u_MVP;

void main()
{
	gl_Position = u_MVP * vec4(position, 1.0);
	v_texture_coord = texture_coord;
	v_color = color;
	v_texture_index = texture_index;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec4 v_color;
in vec2 v_texture_coord;
in float v_texture_index;

uniform sampler2D u_textures[32];

void main()
{
	int index = int(v_texture_index);
	color = texture(u_textures[index], v_texture_coord) * v_color;
}