#pragma once

#include "Command.h"

/// ===== 入力管理クラス ===== ///
class InputHandler {
private:
	// 入力A
	ICommand* pressKeyA_;

	// 入力D
	ICommand* pressKeyD_;

public:
	ICommand* HandleInput();

	/// キーA
	void AssignMoveLeftCommand2PressKeyA();

	/// キーD
	void AssignMoveRightCommand2PressKeyD();
};