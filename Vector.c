#include "..\engine.h"
//vec2
vec2 add2(vec2 a, vec2 b)
{
	return (vec2){a.x + b.x, a.y + b.y};
}
vec2 sub2(vec2 a, vec2 b)
{
	return (vec2){a.x - b.x, a.y - b.y};
}
vec2 mul2(vec2 a, vec2 b)
{
	return (vec2){a.x * b.x, a.y * b.y};
}
vec2 div2(vec2 a, vec2 b)
{
	return (vec2){a.x / b.x, a.y / b.y};
}
f32  dot2(vec2 a, vec2 b)
{
	return a.x * b.x + a.y * b.y;
}
vec2 normalize2(vec2 a)
{
	f32 m = 1/sqrtf(a.x * a.x + a.y * a.y);
	return (vec2){a.x * m, a.y * m};
}
vec2 lerp2(vec2 a, vec2 b, f32 t)
{
	f32 inv = (1-t);
	return (vec2){a.x * t + b.x * inv, a.y * t + b.y * inv};
}
f32  length2(vec2 a, vec2 b)
{
	vec2 sub = (vec2){a.x - b.x, a.y - b.y};
	return sqrtf(sub.x * sub.x + sub.y * sub.y);
}

//vec3
vec3 add3(vec3 a, vec3 b)
{
	return (vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}
vec3 sub3(vec3 a, vec3 b)
{
	return (vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}
vec3 mul3(vec3 a, vec3 b)
{
	return (vec3){a.x * b.x, a.y * b.y, a.z * b.z};
}
vec3 div3(vec3 a, vec3 b)
{
	return (vec3){a.x / b.x, a.y / b.y, a.z / b.z};
}
f32  dot3(vec3 a, vec3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
vec3 cross(vec3 a, vec3 b)
{
	return (vec3){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
vec3 normalize3(vec3 a)
{
	f32 m = 1/sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
	return (vec3){a.x * m, a.y * m, a.z * m};
}
vec3 lerp3(vec3 a, vec3 b, f32 t)
{
	f32 inv = (1-t);
	return (vec3){a.x * t + b.x * inv, a.y * t + b.y * inv, a.z * t + b.z * inv};
}
f32  length3(vec3 a, vec3 b)
{
	vec3 sub = (vec3){a.x - b.x, a.y - b.y, a.z - b.z};
	return sqrtf(sub.x * sub.x + sub.y * sub.y, sub.z * sub.z);
}

//vec4
vec4 add4(vec4 a, vec4 b)
{
	return (vec4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
vec4 sub4(vec4 a, vec4 b)
{
	return (vec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}
vec4 mul4(vec4 a, vec4 b)
{
	return (vec4){a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}
vec4 div4(vec4 a, vec4 b)
{
	return (vec4){a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w};
}
f32  dot4(vec4 a, vec4 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}
vec4 normalize4(vec4 a)
{
	f32 m = 1/sqrtf(a.x * a.x + a.y * a.y + a.z * a.z, a.w * a.w);
	return (vec4){a.x * m, a.y * m, a.z * m, a.w * m};
}
vec4 lerp4(vec4 a, vec4 b, f32 t)
{
	f32 inv = (1-t);
	return (vec4){a.x * t + b.x * inv, a.y * t + b.y * inv, a.z * t + b.z * inv, a.w * t + b.w * inv};
}
f32  length4(vec4 a, vec4 b)
{
	vec4 sub = (vec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
	return sqrtf(sub.x * sub.x + sub.y * sub.y, sub.z * sub.z, sub.w * sub.w);
}

//ivec2
ivec2 iadd2(ivec2 a, ivec2 b)
{
	return (ivec2) { a.x + b.x, a.y + b.y };
}
ivec2 isub2(ivec2 a, ivec2 b)
{
	return (ivec2){a.x - b.x, a.y - b.y};
}
ivec2 imul2(ivec2 a, ivec2 b)
{
	return (ivec2){a.x * b.x, a.y * b.y};
}
ivec2 idiv2(ivec2 a, ivec2 b)
{
	return (ivec2){a.x / b.x, a.y / b.y};
}
i32   idot2(ivec2 a, ivec2 b)
{
	return a.x * b.x + a.y * b.y;
}
ivec2 inormalize2(ivec2 a)
{
	f32 m = 1/sqrtf(a.x * a.x + a.y * a.y);
	return (ivec2){a.x * m, a.y * m};
}
ivec2 ilerp2(ivec2 a, ivec2 b, f32 t)
{
	f32 inv = (1-t);
	return (ivec2){a.x * t + b.x * inv, a.y * t + b.y * inv};
}
i32   ilength2(ivec2 a, ivec2 b)
{
	ivec2 sub = (ivec2){a.x - b.x, a.y - b.y};
	return sqrtf(sub.x * sub.x + sub.y * sub.y);
}

//ivec3
ivec3 iadd3(ivec3 a, ivec3 b)
{
	return (ivec3){a.x + b.x, a.y + b.y, a.z + b.z};
}
ivec3 isub3(ivec3 a, ivec3 b)
{
	return (ivec3){a.x - b.x, a.y - b.y, a.z - b.z};
}
ivec3 imul3(ivec3 a, ivec3 b)
{
	return (ivec3){a.x * b.x, a.y * b.y, a.z * b.z};
}
ivec3 idiv3(ivec3 a, ivec3 b)
{
	return (ivec3){a.x / b.x, a.y / b.y, a.z / b.z};
}
i32   idot3(ivec3 a, ivec3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
ivec3 icross(ivec3 a, ivec3 b)
{
	return (ivec3){a.y * b.z- a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
ivec3 inormalize3(ivec3 a)
{
	f32 m = 1/sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
	return (ivec3){a.x * m, a.y * m, a.z * m};
}
ivec3 ilerp3(ivec3 a, ivec3 b, f32 t)
{
	f32 inv = (1-t);
	return (ivec3){a.x * t + b.x * inv, a.y * t + b.y * inv, a.z * t + b.z * inv};
}
i32   ilength3(ivec3 a, ivec3 b)
{
	ivec3 sub = (ivec3){a.x - b.x, a.y - b.y, a.z - b.z};
	return sqrtf(sub.x * sub.x + sub.y * sub.y + sub.z * sub.z);
}

//ivec4
ivec4 iadd4(ivec4 a, ivec4 b)
{
	return (ivec4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
ivec4 isub4(ivec4 a, ivec4 b)
{
	return (ivec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w + b.w};
}
ivec4 imul4(ivec4 a, ivec4 b)
{
	return (ivec4){a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}
ivec4 idiv4(ivec4 a, ivec4 b)
{
	return (ivec4){a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w};
}
i32   idot4(ivec4 a, ivec4 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}
ivec4 inormalize4(ivec4 a)
{
	f32 m = 1/sqrtf(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
	return (ivec4){a.x * m, a.y * m, a.z * m, a.w * m};
}
ivec4 ilerp4(ivec4 a, ivec4 b, f32 t)
{
	f32 inv = (1-t);
	return (ivec4){a.x * t + b.x * inv, a.y * t + b.y * inv, a.z * t + b.z * inv, a.z * t + b.z * inv};
}
i32  ilength4(ivec4 a, ivec4 b)
{
	ivec4 sub = (ivec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
	return sqrtf(sub.x * sub.x + sub.y * sub.y + sub.z * sub.z, sub.w * sub.w);
}