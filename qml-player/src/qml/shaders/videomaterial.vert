#version 440
layout(location = 0) in vec4 aVertex;
layout(location = 1) in vec2 aTexCoord;
layout(location = 0) out vec2 vTexCoord;
layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;

    mat4 colorMatrix;
} ubuf;
layout(binding = 1) uniform sampler2D texY;
layout(binding = 2) uniform sampler2D texU;
layout(binding = 3) uniform sampler2D texV;
//           "uniform mediump mat4 colorMatrix;"

out gl_PerVertex { vec4 gl_Position; };
void main() {
    gl_Position = ubuf.qt_Matrix * aVertex;
    vTexCoord = aTexCoord;
}
