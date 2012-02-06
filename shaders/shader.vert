varying vec3 vertex_light_position0;
varying vec3 vertex_light_position1;
varying vec3 vertex_normal;

void main() {			
	vertex_normal = normalize(gl_NormalMatrix * gl_Normal);

    vertex_light_position0 = normalize(gl_LightSource[0].position.xyz);
    vertex_light_position1 = normalize(gl_LightSource[1].position.xyz);

    gl_FrontColor = gl_Color;

	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
