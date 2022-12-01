#include <Novice.h>
#include"Inverse.h"
#include"MatrixScreenPrint.h"

const char kWindowTitle[] = "LC1A_06_カツヤマヨウヘイ_確認課題";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Matrix2x2 m1 = {
	1.0f,2.0f,
	3.0f,4.0f };

	Matrix3x3 m2 = {
		1.0f,2.0f,0.0f,
		3.0f,4.0f,0.0f,
		5.0f,6.0f,1.0f
	};

	Matrix2x2 inverseM1;
	Matrix3x3 inverseM2;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		inverseM1 = Inverse(m1);
		inverseM2 = Inverse(m2);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		MatrixScreenPrintf(0,kRowHeight*0,inverseM1);
		MatrixScreenPrintf(0, kRowHeight * 2 + 10, inverseM2);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
