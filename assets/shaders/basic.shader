#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 texture_coord;

out vec2 v_texture_coord;
out vec4 v_color;

uniform mat4 u_MVP;

void main()
{
	gl_Position = u_MVP * vec4(position, 1.0);
	v_texture_coord = texture_coord;
	v_color = color;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec4 v_color;
in vec2 v_texture_coord;

uniform sampler2D u_texture;

void main()
{
	vec4 tex_color = texture(u_texture, v_texture_coord);
	color = tex_color;
}