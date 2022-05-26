/*
uniform sampler2D texY;
uniform sampler2D texU;
uniform sampler2D texV;
uniform mediump mat4 colorMatrix;
varying highp vec2 textureCoord;
uniform lowp float opacity;"
void main(void)"
{  
     highp vec4 color = vec4(
           texture2D(texY, textureCoord.st).r,
           texture2D(texU, textureCoord.st).r,
           texture2D(texV, textureCoord.st).r,
           1.0);
    gl_FragColor = colorMatrix * color * opacity;
}

*/

//https://doc-snapshots.qt.io/qt6-dev/qml-qtquick-shadereffect.html
#version 440
layout(location = 0) in vec2 vTexCoord;
layout(location = 0) out vec4 fragColor;
layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;

    mat4 colorMatrix;
} ubuf;
layout(binding = 1) uniform sampler2D texY;
layout(binding = 2) uniform sampler2D texU;
layout(binding = 3) uniform sampler2D texV;
//layout(binding = 4) uniform mat4 colorMatrix;
void main() {
    //vec4 c = texture(srcTex, vTexCoord);
    vec4 color = vec4(
           texture(texY, vTexCoord.st).r,
           texture(texU, vTexCoord.st).r,
           texture(texV, vTexCoord.st).r,
           1.0);
    fragColor = ubuf.colorMatrix * color * ubuf.qt_Opacity;
}
