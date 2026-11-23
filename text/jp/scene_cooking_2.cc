#include "scene_cooking.hh"

char const gText_StaminaRecoveryStatus[9][29] = {
    "体力回復がかなり低くなった。",
    "体力回復がわりと低くなった。",
    "体力回復が少し低くなった。",
    "体力回復が微妙に低くなった。",
    "体力回復は全く同じ。",
    "体力回復が微妙に高くなった。",
    "体力回復が少し高くなった。",
    "体力回復がわりと高くなった。",
    "体力回復がかなり高くなった。",
};

char const gText_FatigueRecoveryStatus[18][29] = {
    "疲労回復もかなり低くなった。",
    "疲労回復はかなり低くなった。",
    "疲労回復もわりと低くなった。",
    "疲労回復はわりと低くなった。",
    "疲労回復も少し低くなった。",
    "疲労回復は少し低くなった。",
    "疲労回復も微妙に低くなった。",
    "疲労回復は微妙に低くなった。",
    "疲労回復も全く同じ。",
    "疲労回復は全く同じ。",
    "疲労回復も微妙に高くなった。",
    "疲労回復は微妙に高くなった。",
    "疲労回復も少し高くなった。",
    "疲労回復は少し高くなった。",
    "疲労回復もわりと高くなった。",
    "疲労回復はわりと高くなった。",
    "疲労回復もかなり高くなった。",
    "疲労回復はかなり高くなった。",
};

char const gText_Cooking_SeasoningSet[] =
    "調味料セット";

char const gText_Cooking_CompleteUtensilSelection[] =
    "使う調理道具の選択を終了して\r\n"
    "使う材料の選択に移ります。";

char const gText_Cooking_WrappedGiftDescription[] =
    "を\r\n"
    "プレゼント用に包んでもらった\r\n"
    "もの。";

char const gText_Cooking_FollowRecipe[] =
    "レシピ通りに作る";

char const gText_Cooking_ImproviseRecipe[] =
    "アレンジしてみる";

char const gText_Cooking_MakeAnotherRecipe[] =
    "別のお料理を作る";

char const gText_Cooking_NotEnoughIngredients[] =
    "材料が足りないけど…";

char const gText_Cooking_UseTheseIngredients[] =
    "これでお料理を作る";

char const gText_Cooking_RestartIngredients[] =
    "材料選択をやりなおす";

char const gText_Cooking_RestartUtensils[] =
    "調理道具選択からやりなおす";

char const gText_Cooking_ResultFailure[] =
    "失敗しちゃった…{Press}";

char const gText_Cooking_ResultSuccessNewRecipe[] =
    "\xFFが\r\n"
    "できた！\r\n"
    "新しくレシピに書きこもう！{Press}";

char const gText_Cooking_ResultSuccess[] =
    "\xFFの\r\n"
    "できあがり！{Press}";

char const gText_Cooking_ResultComparison[] =
    "前に作ったのに比べて…\r\n"
    "\xF0\r\n"
    "\xF1{Press}";

char const gText_Cooking_Recipe_MakeThis[] =
    "レシピをこれに書きかえる";

char const gText_Cooking_Recipe_LeavePreviousAsIs[] =
    "レシピは前のままにしておく";

char const gText_Cooking_Recipe_ViewCurrent[] =
    "今のレシピを見る";

char const gText_Cooking_Recipe_Rewrite[] =
    "レシピを新しいのに書きかえ";

char const gText_Cooking_Recipe_LeaveNewAsIs[] =
    "レシピはこのままにしておく";

char const gText_Cooking_Recipe_ViewNew[] =
    "新しく出来たレシピを見る";

char const gText_Cooking_Recipe_IngredientsRequired[] =
    "何か材料を選ばないと\r\n"
    "お料理できません。{Press}";

char const gText_Cooking_Recipe_ListTitle[] =
    "作ったことのあるお料理";

char const gText_Cooking_Recipe_Utensils[] =
    "道具";

char const gText_Cooking_Recipe_Ingredients[] =
    "材料";

char const gText_Cooking_Recipe_UseIngredients[] =
    "使う材料";

char const gText_Cooking_Recipe_Empty[] =
    "";

char const gText_Cooking_Recipe_StorageHeader[] =
    "持ち物冷蔵庫";

char const gText_Cooking_Recipe_SelectionNames[13][11] = {
    "　　　　　",
    "包丁　　　",
    "フライパン",
    "なべ　　　",
    "ミキサー　",
    "泡立て器　",
    "めん棒　　",
    "オーブン　",
    "さとう　　",
    "しお　　　",
    "す　　　　",
    "しょうゆ　",
    "みそ　　　",
};
