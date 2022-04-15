//These are defined due to different hardware offering different float solutions.
typedef float  f32;
typedef double f64;

typedef struct vec2 { f32 x, y; } vec2;
typedef struct vec3 { f32 x, y, z; } vec3;
typedef struct vec4 { f32 x, y, z, w; } vec4;

typedef struct ivec2 { i32 x, y; } ivec2;
typedef struct ivec3 { i32 x, y, z; } ivec3;
typedef struct ivec4 { i32 x, y, z, w; } ivec4;

typedef struct quat { f32 x, y, z, w; } quat;
typedef struct mat4 { vec4 r1, r2, r3, r4; } mat4;
typedef void(*funct)(void);

//vec2
vec2 add2(vec2 a, vec2 b);
vec2 sub2(vec2 a, vec2 b);
vec2 mul2(vec2 a, vec2 b);
vec2 div2(vec2 a, vec2 b);
f32  dot2(vec2 a, vec2 b);
vec2 normalize2(vec2 a);
vec2 lerp2(vec2 a, vec2 b, f32 t);
f32  length2(vec2 a, vec2 b);

//vec3
vec3 add3(vec3 a, vec3 b);
vec3 sub3(vec3 a, vec3 b);
vec3 mul3(vec3 a, vec3 b);
vec3 div3(vec3 a, vec3 b);
f32  dot3(vec3 a, vec3 b);
vec3 cross(vec3 a, vec3 b);
vec3 normalize3(vec3 a);
vec3 lerp3(vec3 a, vec3 b, f32 t);
f32  length3(vec3 a, vec3 b);

//vec4
vec4 add4(vec4 a, vec4 b);
vec4 sub4(vec4 a, vec4 b);
vec4 mul4(vec4 a, vec4 b);
vec4 div4(vec4 a, vec4 b);
f32  dot4(vec4 a, vec4 b);
vec4 normalize4(vec4 a);
vec4 lerp4(vec4 a, vec4 b, f32 t);
f32  length4(vec4 a, vec4 b);

//ivec2
ivec2 iadd2(ivec2 a, ivec2 b);
ivec2 isub2(ivec2 a, ivec2 b);
ivec2 imul2(ivec2 a, ivec2 b);
ivec2 idiv2(ivec2 a, ivec2 b);
i32   idot2(ivec2 a, ivec2 b);
ivec2 inormalize2(ivec2 a);
ivec2 ilerp2(ivec2 a, ivec2 b, f32 t);
i32   ilength2(ivec2 a, ivec2 b);

//ivec3
ivec3 iadd3(ivec3 a, ivec3 b);
ivec3 isub3(ivec3 a, ivec3 b);
ivec3 imul3(ivec3 a, ivec3 b);
ivec3 idiv3(ivec3 a, ivec3 b);
i32   idot3(ivec3 a, ivec3 b);
ivec3 icross(ivec3 a, ivec3 b);
ivec3 inormalize3(ivec3 a);
ivec3 ilerp3(ivec3 a, ivec3 b, f32 t);
i32   ilength3(ivec3 a, ivec3 b);

//ivec4
ivec4 iadd4(ivec4 a, ivec4 b);
ivec4 isub4(ivec4 a, ivec4 b);
ivec4 imul4(ivec4 a, ivec4 b);
ivec4 idiv4(ivec4 a, ivec4 b);
i32   idot4(ivec4 a, ivec4 b);
ivec4 inormalize4(ivec4 a);
ivec4 ilerp4(ivec4 a, ivec4 b, f32 t);
i32   ilength4(ivec4 a, ivec4 b);

//quaterions
quat angleAxis(f32 angle, vec3 a);
quat qmul(quat a, quat b);
quat qdiv(quat a, quat b);
quat qinv(quat a);
quat qnormalize(quat a);
quat extractRotation(mat4 matrix, const u32 maxIter);
//matrix
mat4 midentity();
mat4 madd(mat4 a, mat4 b);
mat4 msub(mat4 a, mat4 b);
mat4 mmul(mat4 a, mat4 b);
mat4 minverse(mat4 m);
mat4 mperspective(f32 near_, f32 far_, f32 fov, f32 aspect);
mat4 mview(vec3 eye, vec3 target, vec3 up);
mat4 mquaternion(quat quaternion);
mat4 meular(vec3 eular);