class CfgBlackMarket
{
	StaticBlackMarketIdx[]		= {};				// Static Traders with this index (starts from 0) defined in epoch_server_settings\configs\maps\worldname -> staticNpcPos
													// will always get set to BlackMarkets
													// Example: {0,2} will set the 1st and 3rd defined static trader as a BlackMarket

	BlackMarketTraderCount 		= 2;				// 2 Random Traders will be set to BlackMarkets (change every Restart)
	ShowBlackMarketTraders 		= "true";			// Show Marker for Blackmarket Traders?
	BlackMarketMarkerColor		= "ColorRed";		// Marker color for Blackmarket Traders (if ShowBlackMarketTraders = "true")
	BlackMarketPurchaseMulti	= 5;				// Multi on purchase on top of the default price
	BlackMarketSellMulti		= 0.8;				// Multi on Sell for the default price
	BlackMarketItemsCount		= 50;				// Count of items for each class (will get refilled after each purchase anyway!)

	BlackMarketUseLootList		= "true";			// Use the Epoch LootList to prepare the available Items within the BlackMarket
	BlackMarketExtraItems[]		= {					// Items in BlackMarket, that are not within the LootTable
//		"MBK_01_EPOCH",								// Can be a Vehicle
//		"ItemComboLock"								// Or Items / Magazines
	};
	
	Blackmarket_SpecialPrices[]	= {					// Do not use the default Multis, but this special prices for listed items
//		{"SatchelCharge_Remote_Mag",50,500}			// Sell Price = 50 | Purchase Price = 500
	};

	Blackmarket_BlackList[]		= {					// These classes are not listed in Blackmarket (doesnt matter if in Loot or not)
//		"ItemGoldBar10oz"
	};
};