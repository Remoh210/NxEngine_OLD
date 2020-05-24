#include "common.glh"



#if defined(VS_BUILD)

out vec2 texCoord0;

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 4) in mat4 transformMat;



void main()
{
    gl_Position = vec4(position, 1.0) * transformMat;
    texCoord0 = texCoord;
}

#elif defined(FS_BUILD)
uniform sampler2D diffuse;
in vec2 texCoord0;

layout(location = 0) vec4
DeclareFragOutput(0, vec4);
void main()
{
    gl_FragData[0] = texture2D(diffuse, texCoord0);

}
#endif
