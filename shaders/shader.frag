varying vec3 vertex_light_position0;
varying vec3 vertex_light_position1;
varying vec3 vertex_normal;

void main() {	
    float diffuse_value = max(dot(vertex_normal, vertex_light_position0), 0.0) + max(dot(vertex_normal, vertex_light_position1), 0.0);

	gl_FragColor = gl_Color * diffuse_value;
}
