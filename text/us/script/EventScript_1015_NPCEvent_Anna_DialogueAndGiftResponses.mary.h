mary_text_table
{
    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_Introduction[] =
        "Now, you're a new face\r\n"
        "around here...Oh, I know.\r\n"
        "you're that new boy at {Press}\r\n"
        "the farm!{Press}\p"
        "My name is Anna, and it's\r\n"
        "a pleasure to meet you!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_BirthdayGiftAcknowledgement[] =
        "Really? This is for me?{Press}\p"
        "Usually only my family \r\n"
        "gives me gifts...Thanks!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_FavoriteGiftResponse[] =
        "Thank you so much!\r\n"
        "This is a wonderful \r\n"
// This ordinary gift response is not restricted to birthdays.
#ifdef BUGFIX
        "surprise present!{Press}";
#else
        "surprise birthday present!{Press}";
#endif

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_LikedGiftResponse[] =
        "Thanks for such a \r\n"
        "nice gift!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_NeutralGiftResponse[] =
        "Thanks! I love these!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_DislikedGiftResponse[] =
        "I hate to tell you, but...\r\n"
        "I really hate these!{Press}\p"
        "Still, it is a present, so\r\n"
        "I'll take it...{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_HatedGiftResponse[] =
        "Gross! What is it...?{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_FavorableAnimalResponse[] =
        "It's so cute!{Press}\p"
        "My dad says plants are\r\n"
        "cute... I don’t know why.{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_UnfavorableAnimalResponse[] =
        "Why would you show \r\n"
        "something so nasty\r\n"
        "to me...?!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_AccessoryGiftResponse[] =
        "How lovely! Is it\r\n"
        "a designer brand...?{Press}\p"
        "Just kidding, I bet Saibara \r\n"
        "made it, right?{Press}\p";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_CosmeticGiftResponse[] =
        "Thanks! I was just thinking\r\n"
        "I wanted one of these...{Press}\p"
        "Unlike my husband, you \r\n"
        "know what women want!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_PerfumeGiftResponse[] =
        "What a nice fragrance!\r\n"
        "Women just love to receive\r\n"
        "Perfume, you know. {Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_CommentsOnBlueFeather[] =
        "Ah...a Blue Feather...\r\n"
        "I wish Basil had used one\r\n"
        "to propose to me...{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_MaryChildBornBasilHouse1FFirstConversation[] =
        "Oh, {Player}. \r\n"
        "How is {Baby}? \r\n"
        "I can't wait to meet him!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_MaryChildBornBasilHouse1FRepeatConversation[] =
        "Can you believe it?{Press}\p"
        "Basil wants to take \r\n"
        "{Baby} to the \r\n"
        "mountains to make a {Press}\r\n"
        "botanist out of him!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_BasilHouse1FLowFriendshipFirstConversation[] =
        "Hello, {Player}. {Press}\p"
// Correct read and the possessive Basil's in the library question.
#ifdef BUGFIX
        "Have you read Basil's \r\n"
#else
        "Have you ready Basil \r\n"
#endif
        "books? He has lots \r\n"
        "in the Library.{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_BasilHouse1FLowFriendshipRepeatConversation[] =
        "He says that the books \r\n"
        "about this town are more \r\n"
        "popular than the ones about{Press}\r\n"
        "plants...{Press}\p"
        "I think he wishes it were\r\n"
        "the other way around!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_BasilHouse1FHighFriendshipFirstConversation[] =
        "Hello, {Player}. \r\n"
        "I was just remembering the \r\n"
        "time when Basil chased a {Press}\r\n"
        "butterfly off a cliff!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_BasilHouse1FHighFriendshipRepeatConversation[] =
        "Basil likes to go \r\n"
        "drinking at night...{Press}\p"
        "Men!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_BasilHouse2FSunnyFirstConversation[] =
        "Good morning, {Player}. \r\n"
        "Another tough day, huh?{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_BasilHouse2FSunnyRepeatConversation[] =
        "I kind of envy you,\r\n"
        "{Player}. {Press}\p"
        "You see...I get bored with \r\n"
        "nothing to do!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_BasilHouse2FRainyFirstConversation[] =
        "I see it's raining today.\r\n"
        "I hope Basil doesn't \r\n"
        "catch cold!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_BasilHouse2FRainyRepeatConversationPart1[] =
        "I was praying for \r\n"
        "good weather last night, \r\n"
        "but look at this!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_BasilHouse2FRainyRepeatConversationPart2[] =
        "That Basil doesn't care\r\n"
        "if it rains or pours.  \r\n"
        "He loves looking at plants!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_NorthSideTownEveningConversation[] =
        "I wonder what I should do \r\n"
        "when I get home...{Press}\p"
        "Basil won't play with me\r\n"
        "anyway...Hmmph!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_NorthSideTownNonMondayDaytimeConversation[] =
        "Most of the wives in town\r\n"
        "gather at Rose Square \r\n"
        "around noon.{Press}\p"
        "I don't bring Basil, though.\r\n"
        "He only talks about plants!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_NorthSideTownMondayDaytimeConversation[] =
        "Hello, {Player}. \r\n"
        "I'm happy to see you \r\n"
        "looking happy and healthy!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_SupermarketLowFriendshipFirstConversation[] =
        "Today is my shopping day. {Press}\p"
        "I like going to the \r\n"
        "Supermarket to buy things.{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_SupermarketLowFriendshipRepeatConversation[] =
        "Have you been watching the\r\n"
        "TV Shopping Network?{Press}\p"
        "I suggest a Pot. You can't\r\n"
        "cook anything without it!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_SupermarketHighFriendshipFirstConversation[] =
        "Jeff works so hard, too.{Press}\p"
        "It must be hard, \r\n"
        "running a store!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_SupermarketHighFriendshipRepeatConversation[] =
        "I don't run up a tab!\r\n"
        "But...Sometimes I do \r\n"
        "forget my wallet...{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_RoseSquareFirstConversation[] =
        "Mister......did....\r\n"
        "...Can you believe....\r\n"
        "then...his wife...{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_RoseSquareRepeatConversation[] =
        "In order to heal her, \r\n"
        "Lillia's husband went off\r\n"
        "to find a flower that only{Press}\r\n"
        "blooms in the desert once\r\n"
        "every ten years.{Press}\p"
        "I think she's lonely \r\n"
        "him...{Press}\p"
        "Maybe I shouldn't have told\r\n"
        "him about that flower!...{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_MothersHillMiddleLowFriendshipFirstConversation[] =
        "Our Monday hiking days\r\n"
        "are prime family time. {Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_MothersHillMiddleLowFriendshipRepeatConversation[] =
        "But, all we do is talk\r\n"
        "about plants! I'm worried \r\n"
        "Mary won't know about{Press}\r\n"
        "normal things!{Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_MothersHillMiddleHighFriendshipFirstConversation[] =
        "Still, Mother's Hill is fun\r\n"
        "because so many things \r\n"
        "grow there. {Press}";

    const char gText_NPCEvent_Anna_DialogueAndGiftResponses_MothersHillMiddleHighFriendshipRepeatConversation[] =
        "Maybe I'll make \r\n"
        "some more jam...{Press}";
};
