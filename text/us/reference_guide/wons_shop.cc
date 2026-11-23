// fomt-text input, intentionally not a C++ translation unit.
// TITLE is fixed at the top of the screen; MAIN rows scroll below it.
TITLE
    "Won's Shop"
MAIN
    "·Won sells Seeds not "
    " available at the Super-"
    " market and some Dog"
    " training Tools."
    ""
    "·Location:"
    " Zack's house at Mineral "
    " Beach"
    ""
    ""
    "☆Seeds"
    "·Plant Seeds and water "
    " every day to grow crops."
// Restore the growing-season warning using the supermarket guide wording.
#ifdef BUGFIX
    " Be careful, some crops "
    " only grow in some seasons."
#else
    "  different seasons."
#endif
    ""
// Won keeps the same seed assortment in every season.
#ifdef BUGFIX
    "·The same Seeds are sold"
    " in every season."
#else
    "·Different Seeds are sold"
    " in different seasons."
#endif
    ""
    ""
    "☆Dog Ball"
    "☆Frisbee"
    "·Toys to train "
    " fully grown Dogs"
    ""
    " You can only buy one,"
    " but if you lose yours "
    " Won will sell you another."
    ""
    " Not sold at first, but "
    " they go on sale after"
    " a while."
    ""
    "☆Jewels of Truth"
    "·Collect 9 and something"
    " good is rumored to "
    " happen. "
END_FOMT_REFERENCE_GUIDE_PAGE
