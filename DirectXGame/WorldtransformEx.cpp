#include "WorldtransformEx.h"

using namespace KamataEngine;
using namespace KamataEngine::MathUtility;

// Scale,Rotation,Translate行列からWorld行列を計算、定数バッファへの転送を行う
void WorldTransformEx::UpdateMatrix() {
	// World変換行列を計算し、matWorld_へ格納する
	matWorld_ = MakeAffineMatrix();
	// 定数バッファへ転送する
	TransferMatrix();
}

// アフィン変換行列を作る
Matrix4x4 WorldTransformEx::MakeAffineMatrix()  {
	//Scale Matrix
	Matrix4x4 matScale = MakeScaleMatrix(scale_);

	//Rotation Matrix
	Matrix4x4 matRotX = MakeRotateXMatrix(rotation_.x);
	Matrix4x4 matRotY = MakeRotateYMatrix(rotation_.y);
	Matrix4x4 matRotZ = MakeRotateZMatrix(rotation_.z);
	Matrix4x4 matRot = matRotZ * matRotX * matRotY;

	//Translate Matrix
	Matrix4x4 matTrans = MakeTranslateMatrix(translation_);

	//WorldMatrix
	Matrix4x4 matWorld = matScale * matRot * matTrans;

	return matWorld;
}