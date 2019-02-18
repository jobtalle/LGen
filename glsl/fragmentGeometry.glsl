in vec3 interpolatedColor;
out vec4 color;

void main()
{
	color = vec4(interpolatedColor, 1);
}