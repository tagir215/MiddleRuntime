#pragma once
#include <raymath.h>
#include "middle_math.h"
#include "rlgl.h"
#include "middle_state.h"


inline static Vector3 toRPos(const middle::RenderData& data, int index) {
	return { data.positionsX[index], data.positionsY[index], data.positionsZ[index] };
}
inline static Vector3 toRScale(const middle::RenderData& data, int index) {
	return { data.scalesX[index], data.scalesY[index], data.scalesZ[index] };
}
inline static Quaternion toRRot(const middle::RenderData& data, int index) {
	return { data.rotationsX[index], data.rotationsY[index], data.rotationsZ[index], data.rotationsW[index]};
}
inline static Transform toRTransform(const middle::RenderData& data, int index) {
	Vector3 pos = toRPos(data, index);
	Quaternion rot = toRRot(data, index);
	Vector3 scale = toRScale(data, index);
	Transform transform;
	transform.translation = pos;
	transform.rotation = rot;
	transform.scale = scale;
	return transform;
}

inline static Vector3 toRVec(const midMath::Vector3& vec) {
	return { vec.x,vec.y,vec.z };
}
inline static Color toRColor(const midPrimitive::Color& col) {
	return { col.r, col.g, col.b, col.a };
}
inline static Quaternion toRQuat(const midMath::Quaternion& quat) {
	return { quat.x,quat.y,quat.z,quat.w };
}
inline static Transform toRTransform(const midPrimitive::Transform& tra) {
	return {
		toRVec(tra.translation),
		toRQuat(tra.rotation),
		toRVec(tra.scale)
	};
}
inline static Camera3D toRCam(const midPrimitive::Camera& cam) {
	return Camera3D{
		toRVec(cam.position),
		toRVec(cam.target),
		toRVec(cam.up),
		cam.fovy,
		cam.projection
	};
}
inline static Texture2D toRTexture(midPrimitive::Texture2D& texture) {
	return Texture2D{
		texture.id,
		texture.width,
		texture.height,
		texture.mipmaps,
		texture.format
	};
}
inline static Shader toRShader(midPrimitive::Shader& shader) {
	return Shader{
		shader.id,
		shader.locs
	};
}


inline static Matrix transformMatrix(Transform& transform) {
	Matrix S = MatrixScale(transform.scale.x, transform.scale.y, transform.scale.z);
	Matrix R = QuaternionToMatrix(transform.rotation);
	Matrix T = MatrixTranslate(transform.translation.x, transform.translation.y, transform.translation.z);
	Matrix M = MatrixMultiply(MatrixMultiply(S, R), T);
	return M;
}

inline void pushMatrix(Transform& transform) {
	Matrix M = transformMatrix(transform);
	rlPushMatrix();
	rlLoadIdentity();
	rlMultMatrixf(MatrixToFloatV(M).v);
}
