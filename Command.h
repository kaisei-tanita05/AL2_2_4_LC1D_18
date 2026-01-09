#pragma once

/// ===== プレイヤー ===== ///
class Player;

/// ===== コマンドインタフェース ===== ///
class ICommand {

	///-------------------------------------------///
	/// メンバ関数
	///-------------------------------------------///
public:
	/// <summary>
	/// 仮想デストラクタ
	/// </summary>
	virtual ~ICommand();

	/// <summary>
	/// 実行
	/// </summary>
	/// <param name="player">プレイヤー</param>
	virtual void Execute(Player& player) = 0;
};

class MoveRightCommand : public ICommand {

	///-------------------------------------------///
	/// メンバ関数
	///-------------------------------------------///
public:
	/// <summary>
	/// 実行(継承)
	/// </summary>
	/// <param name="player">プレイヤー</param>
	void Execute(Player& player) override;
};

class MoveLeftCommand : public ICommand {

	///-------------------------------------------///
	/// メンバ関数
	///-------------------------------------------///
public:
	/// <summary>
	/// 実行(継承)
	/// </summary>
	/// <param name="player">プレイヤー</param>
	void Execute(Player& player) override;
};