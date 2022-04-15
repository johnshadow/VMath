#include "..\engine.h"
mat4 midentity()
{
	return (mat4){ 
	(vec4){1, 0, 0, 0},
	(vec4){0, 1, 0, 0},
	(vec4){0, 0, 1, 0},
	(vec4){0, 0, 0, 1}
	};
}
mat4 madd(mat4 a, mat4 b)
{
	mat4 dest;
	dest.r1 = add4(a.r1, b.r1);
	dest.r2 = add4(a.r2, b.r2);
	dest.r3 = add4(a.r3, b.r3);
	dest.r4 = add4(a.r4, b.r4);
	return dest;
}
mat4 msub(mat4 a, mat4 b)
{
	mat4 dest;
	dest.r1 = sub4(a.r1, b.r1);
	dest.r2 = sub4(a.r2, b.r2);
	dest.r3 = sub4(a.r3, b.r3);
	dest.r4 = sub4(a.r4, b.r4);
	return dest;
}
mat4 mmul(mat4 a, mat4 b)
{
	mat4 dest;
	dest.r1.x = a.r1.x * b.r1.x + a.r2.x * b.r1.y + a.r3.x * b.r1.z + a.r4.x * b.r1.w;
	dest.r1.y = a.r1.y * b.r1.x + a.r2.y * b.r1.y + a.r3.y * b.r1.z + a.r4.y * b.r1.w;
	dest.r1.z = a.r1.z * b.r1.x + a.r2.z * b.r1.y + a.r3.z * b.r1.z + a.r4.z * b.r1.w;
	dest.r1.w = a.r1.w * b.r1.x + a.r2.w * b.r1.y + a.r3.w * b.r1.z + a.r4.w * b.r1.w;

	dest.r2.x = a.r1.x * b.r2.x + a.r2.x * b.r2.y + a.r3.x * b.r2.z + a.r4.x * b.r2.w;
	dest.r2.y = a.r1.y * b.r2.x + a.r2.y * b.r2.y + a.r3.y * b.r2.z + a.r4.y * b.r2.w;
	dest.r2.z = a.r1.z * b.r2.x + a.r2.z * b.r2.y + a.r3.z * b.r2.z + a.r4.z * b.r2.w;
	dest.r2.w = a.r1.w * b.r2.x + a.r2.w * b.r2.y + a.r3.w * b.r2.z + a.r4.w * b.r2.w;

	dest.r3.x = a.r1.x * b.r3.x + a.r2.x * b.r3.y + a.r3.x * b.r3.z + a.r4.x * b.r3.w;
	dest.r3.y = a.r1.y * b.r3.x + a.r2.y * b.r3.y + a.r3.y * b.r3.z + a.r4.y * b.r3.w;
	dest.r3.z = a.r1.z * b.r3.x + a.r2.z * b.r3.y + a.r3.z * b.r3.z + a.r4.z * b.r3.w;
	dest.r3.w = a.r1.w * b.r3.x + a.r2.w * b.r3.y + a.r3.w * b.r3.z + a.r4.w * b.r3.w;

	dest.r4.x = a.r1.x * b.r4.x + a.r2.x * b.r4.y + a.r3.x * b.r4.z + a.r4.x * b.r4.w;
	dest.r4.y = a.r1.y * b.r4.x + a.r2.y * b.r4.y + a.r3.y * b.r4.z + a.r4.y * b.r4.w;
	dest.r4.z = a.r1.z * b.r4.x + a.r2.z * b.r4.y + a.r3.z * b.r4.z + a.r4.z * b.r4.w;
	dest.r4.w = a.r1.w * b.r4.x + a.r2.w * b.r4.y + a.r3.w * b.r4.z + a.r4.w * b.r4.w;
	return dest;
}
mat4 minverse(mat4 m)
{
    mat4 inv;
	f32 det;
    int i;

    inv.r1.x = m.r2.y  * m.r3.z * m.r4.w - 
             m.r2.y  * m.r3.w * m.r4.z - 
             m.r3.y  * m.r2.z  * m.r4.w + 
             m.r3.y  * m.r2.w  * m.r4.z +
             m.r4.y * m.r2.z  * m.r3.w - 
             m.r4.y * m.r2.w  * m.r3.z;

    inv.r2.x = -m.r2.x  * m.r3.z * m.r4.w + 
              m.r2.x  * m.r3.w * m.r4.z + 
              m.r3.x  * m.r2.z  * m.r4.w - 
              m.r3.x  * m.r2.w  * m.r4.z - 
              m.r4.x * m.r2.z  * m.r3.w + 
              m.r4.x * m.r2.w  * m.r3.z;

    inv.r3.x = m.r2.x  * m.r3.y * m.r4.w - 
             m.r2.x  * m.r3.w * m.r4.y - 
             m.r3.x  * m.r2.y * m.r4.w + 
             m.r3.x  * m.r2.w * m.r4.y + 
             m.r4.x * m.r2.y * m.r3.w - 
             m.r4.x * m.r2.w * m.r3.y;

    inv.r4.x = -m.r2.x  * m.r3.y * m.r4.z + 
               m.r2.x  * m.r3.z * m.r4.y +
               m.r3.x  * m.r2.y * m.r4.z - 
               m.r3.x  * m.r2.z * m.r4.y - 
               m.r4.x * m.r2.y * m.r3.z + 
               m.r4.x * m.r2.z * m.r3.y;

    inv.r1.y = -m.r1.y  * m.r3.z * m.r4.w + 
              m.r1.y  * m.r3.w * m.r4.z + 
              m.r3.y  * m.r1.z * m.r4.w - 
              m.r3.y  * m.r1.w * m.r4.z - 
              m.r4.y * m.r1.z * m.r3.w + 
              m.r4.y * m.r1.w * m.r3.z;

    inv.r2.y = m.r1.x  * m.r3.z * m.r4.w - 
             m.r1.x  * m.r3.w * m.r4.z - 
             m.r3.x  * m.r1.z * m.r4.w + 
             m.r3.x  * m.r1.w * m.r4.z + 
             m.r4.x * m.r1.z * m.r3.w - 
             m.r4.x * m.r1.w * m.r3.z;

    inv.r3.y = -m.r1.x  * m.r3.y * m.r4.w + 
              m.r1.x  * m.r3.w * m.r4.y + 
              m.r3.x  * m.r1.y * m.r4.w - 
              m.r3.x  * m.r1.w * m.r4.y - 
              m.r4.x * m.r1.y * m.r3.w + 
              m.r4.x * m.r1.w * m.r3.y;

    inv.r4.y = m.r1.x  * m.r3.y * m.r4.z - 
              m.r1.x  * m.r3.z * m.r4.y - 
              m.r3.x  * m.r1.y * m.r4.z + 
              m.r3.x  * m.r1.z * m.r4.y + 
              m.r4.x * m.r1.y * m.r3.z - 
              m.r4.x * m.r1.z * m.r3.y;

    inv.r1.z = m.r1.y  * m.r2.z * m.r4.w - 
             m.r1.y  * m.r2.w * m.r4.z - 
             m.r2.y  * m.r1.z * m.r4.w + 
             m.r2.y  * m.r1.w * m.r4.z + 
             m.r4.y * m.r1.z * m.r2.w - 
             m.r4.y * m.r1.w * m.r2.z;

    inv.r2.z = -m.r1.x  * m.r2.z * m.r4.w + 
              m.r1.x  * m.r2.w * m.r4.z + 
              m.r2.x  * m.r1.z * m.r4.w - 
              m.r2.x  * m.r1.w * m.r4.z - 
              m.r4.x * m.r1.z * m.r2.w + 
              m.r4.x * m.r1.w * m.r2.z;

    inv.r3.z = m.r1.x  * m.r2.y * m.r4.w - 
              m.r1.x  * m.r2.w * m.r4.y - 
              m.r2.x  * m.r1.y * m.r4.w + 
              m.r2.x  * m.r1.w * m.r4.y + 
              m.r4.x * m.r1.y * m.r2.w - 
              m.r4.x * m.r1.w * m.r2.y;

    inv.r4.z = -m.r1.x  * m.r2.y * m.r4.z + 
               m.r1.x  * m.r2.z * m.r4.y + 
               m.r2.x  * m.r1.y * m.r4.z - 
               m.r2.x  * m.r1.z * m.r4.y - 
               m.r4.x * m.r1.y * m.r2.z + 
               m.r4.x * m.r1.z * m.r2.y;

    inv.r1.w = -m.r1.y * m.r2.z * m.r3.w + 
              m.r1.y * m.r2.w * m.r3.z + 
              m.r2.y * m.r1.z * m.r3.w - 
              m.r2.y * m.r1.w * m.r3.z - 
              m.r3.y * m.r1.z * m.r2.w + 
              m.r3.y * m.r1.w * m.r2.z;

    inv.r2.w = m.r1.x * m.r2.z * m.r3.w - 
             m.r1.x * m.r2.w * m.r3.z - 
             m.r2.x * m.r1.z * m.r3.w + 
             m.r2.x * m.r1.w * m.r3.z + 
             m.r3.x * m.r1.z * m.r2.w - 
             m.r3.x * m.r1.w * m.r2.z;

    inv.r3.w = -m.r1.x * m.r2.y * m.r3.w + 
               m.r1.x * m.r2.w * m.r3.y + 
               m.r2.x * m.r1.y * m.r3.w - 
               m.r2.x * m.r1.w * m.r3.y - 
               m.r3.x * m.r1.y * m.r2.w + 
               m.r3.x * m.r1.w * m.r2.y;

    inv.r4.w = m.r1.x * m.r2.y * m.r3.z - 
              m.r1.x * m.r2.z * m.r3.y - 
              m.r2.x * m.r1.y * m.r3.z + 
              m.r2.x * m.r1.z * m.r3.y + 
              m.r3.x * m.r1.y * m.r2.z - 
              m.r3.x * m.r1.z * m.r2.y;

    det = m.r1.x * inv.r1.x + m.r1.y * inv.r2.x + m.r1.z * inv.r3.x + m.r1.w * inv.r4.x;

    if (det == 0)
    {
		inv.r1 = (vec4) { 0, 0, 0, 0 };
		inv.r2 = (vec4) { 0, 0, 0, 0 };
		inv.r3 = (vec4) { 0, 0, 0, 0 };
		inv.r4 = (vec4) { 0, 0, 0, 0 };
		return inv;
	}

    det = 1.0 / det;

	inv.r1 = (vec4) { inv.r1.x * det, inv.r1.y * det, inv.r1.z * det, inv.r1.w * det};
	inv.r2 = (vec4) { inv.r2.x * det, inv.r2.y * det, inv.r2.z * det, inv.r2.w * det };
	inv.r3 = (vec4) { inv.r3.x * det, inv.r3.y * det, inv.r3.z * det, inv.r3.w * det };
	inv.r4 = (vec4) { inv.r4.x * det, inv.r4.y * det, inv.r4.z * det, inv.r4.w * det };

    return inv;
}
mat4 mperspective(f32 near_, f32 far_, f32 fov, f32 aspect)
{
	mat4 dest;
	float scale = tan(fov * 0.5 * M_PI / 180) * near_;
	float r = aspect * scale;
	float l = -r;
	float t = scale;
	float b = -t;
	// set OpenGL perspective projection matrix
	dest.r1.x = 2 * near_ / (r - l);
	dest.r1.y = 0;
	dest.r1.z = 0;
	dest.r1.w = 0;

	dest.r2.x = 0;
	dest.r2.y = 2 * near_ / (t - b);
	dest.r2.z = 0;
	dest.r2.w = 0;

	dest.r3.x = (r + l) / (r - l);
	dest.r3.y = (t + b) / (t - b);
	dest.r3.z = -(far_ + near_) / (far_ - near_);
	dest.r3.w = -1;

	dest.r4.x = 0;
	dest.r4.y = 0;
	dest.r4.z = -2 * far_ * near_ / (far_ - near_);
	dest.r4.w = 0;
	return dest;
}
mat4	mview(vec3 eye, vec3 target, vec3 up)
{
	mat4  dest;
	vec3 x, y, z;
	z = normalize3(sub3(eye, target));
	x = normalize3(cross(up, z));
	y = cross(z, x);
	dest.r1 = (vec4) { x.x, y.x, z.x, 0.0 };
	dest.r2 = (vec4) { x.y, y.y, z.y, 0.0 };
	dest.r3 = (vec4) { x.z, y.z, z.z, 0.0 };
	dest.r4 = (vec4) { -dot3(eye, x), -dot3(eye, y), -dot3(eye, z), 1.0 };
	return dest;
}
mat4 mquaternion(quat q)
{
	q = qnormalize(q);
	mat4 dest = midentity();
	f32 L = (q.x * q.x + q.y * q.y + q.z * q.z);
	f32 angle = q.w * M_PI; //converting to radian value
	f32 x2 = q.x * q.x;
	f32 y2 = q.y * q.y;
	f32 z2 = q.z * q.z;

	dest.r1 =
		(vec4) {
		(x2 + (y2 + z2) * cos(angle)) / L,
		(q.x * q.y * (1 - cos(angle)) - q.z * sqrt(L) * sin(angle)) / L,
		(q.x * q.z * (1 - cos(angle)) + q.y * sqrt(L) * sin(angle)) / L,
		0.0
	};
	dest.r2 =
		(vec4) {
		(q.x * q.y * (1 - cos(angle)) + q.z * sqrt(L) * sin(angle)) / L,
		(y2 + (x2 + z2) * cos(angle)) / L,
		(q.y * q.z * (1 - cos(angle)) - q.x * sqrt(L) * sin(angle)) / L,
		0.0
	};
	dest.r3 =
		(vec4) {
		(q.x * q.z * (1 - cos(angle)) - q.y * sqrt(L) * sin(angle)) / L,
		(q.y * q.z * (1 - cos(angle)) + q.x * sqrt(L) * sin(angle)) / L,
		(z2 + (x2 + y2) * cos(angle)) / L,
		0.0
	};
	return dest;
}
mat4 meular(vec3 eular)
{
	mat4 dest;
	dest.r1 = (vec4) { 0, 0, 0, 0 };
	dest.r2 = (vec4) { 0, 0, 0, 0 };
	dest.r3 = (vec4) { 0, 0, 0, 0 };
	dest.r4 = (vec4) { 0, 0, 0, 0 };
	// Assuming the angles are in radians.
    f32 ch = cosf(eular.x);
    f32 sh = sinf(eular.x);
    f32 ca = cosf(eular.y);
    f32 sa = sinf(eular.y);
    f32 cb = cosf(eular.z);
    f32 sb = sinf(eular.z);

    dest.r1.x = ch * ca;
    dest.r1.y = sh*sb - ch*sa*cb;
    dest.r1.z = ch*sa*sb + sh*cb;
    dest.r2.x = sa;
    dest.r2.y = ca*cb;
    dest.r2.z = -ca*sb;
    dest.r3.x = -sh*ca;
    dest.r3.y = sh*sa*cb + ch*sb;
    dest.r3.z = -sh*sa*sb + ch*cb;
	dest.r4.w = 1.0;
	return dest;
}