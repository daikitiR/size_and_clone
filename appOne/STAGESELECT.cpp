#include "STAGESELECT.h"
#include "CONTAINER.h"
STAGESELECT::STAGESELECT(class GAME* game) :
	SCENE(game) {

}
STAGESELECT::~STAGESELECT() {

}
//void STAGESELECT::newLineText() {
//	const int Size = StageSelect.chars;
//	const int NewLineLimit = 5;
//	const int NumberofElements = Size / NewLineLimit;
//	int count = 0;
//	int charnum = 0;
//	char str[NewLineLimit][NumberofElements]{ {} };
//	for (int i = 0; i < strlen(StageSelect.string[0].explain); i++) {
//		if (StageSelect.string[0].explain[i] == '\n') {
//			count++;
//			/*if (count < NewLineLimit) {
//				break;
//			}*/
//			strncpy_s(&str[0][0], NumberofElements, &StageSelect.string[0].explain[0], i);
//			//str[0][5] = '\0';
//
//		}
//		textSize(StageSelect.expTextSize);
//		text(StageSelect.string[0].explain, StageSelect.string[0].pos.x, StageSelect.string[0].pos.y);
//		text(str[0],                    StageSelect.string[0].exppos.x, StageSelect.string[0].exppos.y);
//	}
//}
void STAGESELECT::draw() {
	clear(StageSelect.backColor);
	fill(StageSelect.textColor);
	//左上のステージ画像
	image(SS_Images.image, SS_Images.pos.x, SS_Images.pos.y, SS_Images.angle, SS_Images.size);
	//右上のステージ名
	textSize(StageSelect.textSize);
	text(StageSelect.string[0].str, StageSelect.string[0].pos.x, StageSelect.string[0].pos.y);
	//右の説明欄
	textSize(StageSelect.expTextSize);
	text(StageSelect.string[0].explain, StageSelect.string[0].exppos.x, StageSelect.string[0].exppos.y);
	//newLineText();
	//下の四角い説明欄
	fill(255);
	rectMode(CENTER);
	rect(width / 2, SS_Images.pos.y * 8, width / 1.2, 200);
	//さらにその下のページ数
	fill(0);
	for (int i = 0; i < StageSelect.stageNum; i++) {
		//左右に動かしてステージ選択をしてそれの戻り値をif文に渡して参照するそれをfillで透過に通す
		rect(StageSelect.selectBlock[i].pos.x, StageSelect.selectBlock[i].pos.y, StageSelect.selectBlock[i].Size, StageSelect.selectBlock[i].Size);
	}
	rectMode(CORNER);
}
void STAGESELECT::create() {
	StageSelect = game()->container()->stageselect();
	SS_Images = game()->container()->stage_select_image();
}
void STAGESELECT::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_ID);
	}
}