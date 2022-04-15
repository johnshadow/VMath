#include "..\engine.h"
quat angleAxis(f32 angle, vec3 a)
{
	quat quat;
	quat.w = cos(angle / 2);
	quat.x = a.x * sin(angle / 2);
	quat.y = a.y * sin(angle / 2);
	quat.z = a.z * sin(angle / 2);
	return quat;
}
quat qmul(quat a, quat b)
{
	quat quat;
    quat.x =  a.x * b.w + a.y * b.z - a.z * b.y + a.w * b.x;
    quat.y = -a.x * b.z + a.y * b.w + a.z * b.x + a.w * b.y;
    quat.z =  a.x * b.y - a.y * b.x + a.z * b.w + a.w * b.z;
    quat.w = -a.x * b.x - a.y * b.y - a.z * b.z + a.w * b.w;
	return quat;
}
quat qdiv(quat a, quat b)
{
	f32 norm = 1/(b.x * b.x + b.y  * b.y + b.z * b.z + b.w * b.w);
	quat quat1 = (quat){b.w * norm, -b.x * norm, -b.y * norm, -b.z * norm};
	return qmul(a, quat1);
}
quat qinv(quat a)
{
	f32 norm = 1/(a.x * a.x + a.y  * a.y + a.z * a.z + a.w * a.w);
	quat quat1 = (quat){a.w * norm, -a.x * norm, -a.y * norm, -a.z * norm};
	return quat1;
}
quat qnormalize(quat a)
{
	f32 m = 1 / sqrtf(a.x * a.x + a.y * a.y + a.z * a.z, a.w * a.w);
	return (quat) { a.x * m, a.y * m, a.z * m, a.w * m };
}
quat extractRotation(mat4 matrix, const u32 maxIter)
{
	quat q = (quat){1, 1, 1, 1};
	for (u32 iter = 0; iter < maxIter; iter++)
	{	
		mat4 rotation = midentity();
		rotation = mquaternion(q);
		vec3 rcol0 = (vec3) { rotation.r1.x, rotation.r1.y, rotation.r1.z },
			 rcol1 = (vec3) { rotation.r2.x, rotation.r2.y, rotation.r2.z }, 
			 rcol2 = (vec3) { rotation.r3.x, rotation.r3.y, rotation.r3.z },
			 acol0 = (vec3) { matrix.r1.x, matrix.r1.y, matrix.r1.z },
			 acol1 = (vec3) { matrix.r2.x, matrix.r2.y, matrix.r2.z },
			 acol2 = (vec3) { matrix.r3.x, matrix.r3.y, matrix.r3.z };
		f32 det = 1.0 / fabs(dot3(rcol0, acol0) + dot3(rcol1, acol1) + dot3(rcol2, acol2)) + 1.0e-9;
		vec3 omega = 
			mul3(add3(add3(cross(rcol0, acol0), cross(rcol1, acol1)), cross(rcol2, acol2)), //find cross products vectors
			(vec3) {det, det, det}); //find dot angles add epsilon 
		vec3 nomega = normalize3(omega);
		f64 w = nomega.x + nomega.y + nomega.z;
		if (w < 1.0e-9)
			break;
		q = qmul(angleAxis(w, mul3((vec3) { w, w, w }, omega)), q);
		q = qnormalize(q); //get's quat
	}
	return q;
}