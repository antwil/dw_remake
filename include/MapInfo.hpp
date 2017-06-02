#ifndef MAPINFO_HPP_INCLUDED
#define MAPINFO_HPP_INCLUDED

#include "Constants.hpp"
#include <stdio.h>
#include <string>
#include <map>
#include <tuple>

using namespace std;
typedef pair<int, int> MapPoint;

//Maps exits on a map to spawn locations on the next map
const map<MapPoint, string> overworld_exits =
{
    { MapPoint( 57, 48 ), "brecconary" },
    { MapPoint( 11, 9 ), "garinham" },
    { MapPoint( 90, 8 ), "north_shrine" },
    { MapPoint( 113, 17), "kol" }
};

const map<MapPoint, string> brecconary_exits =
{
    //Exits from left
    { MapPoint( 8, 21 ), "overworld" },
    { MapPoint( 8, 22 ), "overworld" },
    { MapPoint( 8, 23 ), "overworld" },
    { MapPoint( 8, 24 ), "overworld" },

    //Exits from right
    { MapPoint( 39, 21 ), "overworld" },
    { MapPoint( 39, 22 ), "overworld" },
    { MapPoint( 39, 23 ), "overworld" },
    { MapPoint( 39, 24 ), "overworld" },
    { MapPoint( 39, 25 ), "overworld" },

    //Exits from top
    { MapPoint( 22, 7 ), "overworld" },
    { MapPoint( 23, 7 ), "overworld" },
    { MapPoint( 24, 7 ), "overworld" },
    { MapPoint( 25, 7 ), "overworld" }

    //Entrances to buildings

};

const map<MapPoint, string> garinham_exits =
{
    //Exits from left
    { MapPoint( 8, 21 ), "overworld" },
    { MapPoint( 8, 22 ), "overworld" },
    { MapPoint( 8, 23 ), "overworld" },

    //Exits from right
    { MapPoint( 29, 19 ), "overworld" },
    { MapPoint( 29, 20 ), "overworld" },
    { MapPoint( 29, 21 ), "overworld" },
    { MapPoint( 29, 22 ), "overworld" },
    { MapPoint( 29, 8 ), "overworld" },
    { MapPoint( 29, 9 ), "overworld" },

    //Exits from bottom
    { MapPoint( 22, 28 ), "overworld" },

    //Exits from top
    { MapPoint( 12, 7 ), "overworld" },
    { MapPoint( 13, 7 ), "overworld" },
    { MapPoint( 14, 7 ), "overworld" },
    { MapPoint( 15, 7 ), "overworld" },
    { MapPoint( 16, 7 ), "overworld" },
    { MapPoint( 17, 7 ), "overworld" },
    { MapPoint( 18, 7 ), "overworld" },
    { MapPoint( 19, 7 ), "overworld" },
    { MapPoint( 20, 7 ), "overworld" },
    { MapPoint( 21, 7 ), "overworld" },
    { MapPoint( 22, 7 ), "overworld" },
    { MapPoint( 23, 7 ), "overworld" },
    { MapPoint( 24, 7 ), "overworld" },
    { MapPoint( 28, 7 ), "overworld" }

    //Entrance to building

};

const map<MapPoint, string> north_shrine_exits =
{
    { MapPoint( 12, 16 ), "overworld" }
};

const map<MapPoint, string> kol_exits =
{
    { MapPoint( 28, 32 ), "overworld" }
};

//Treasure tables (chests and hidden treasures)
const map<MapPoint, pair<int, string>> overworld_treasure =
{

};

const map<MapPoint, pair<int, string>> brecconary_treasure =
{

};

const map<MapPoint, pair<int, string>> garinham_treasure =
{

};

const map<MapPoint, pair<int, string>> north_shrine_treasure =
{
    { MapPoint( 11, 11 ), pair<int, string>( TREASURE_CHEST, "Staff of Rain" ) }
};

const map<MapPoint, pair<int, string>> kol_treasure =
{
    { MapPoint( 18, 14 ), pair<int, string>( HIDDEN_ITEM, "Fairy Flute" ) }
};

//Maps a pair of names of castles/towns/caves to a coordinate pair location
//where the player will load when transitioning to the latter from the former
const map<pair<string, string>, MapPoint> locations =
{
    { pair<string, string>( "overworld", "brecconary" ), MapPoint( 9, 23 ) },
    { pair<string, string>( "brecconary", "overworld" ), MapPoint( 57, 48 ) },
    { pair<string, string>( "overworld", "garinham" ), MapPoint( 28, 20 ) },
    { pair<string, string>( "garinham", "overworld" ), MapPoint( 11, 9 ) },
    { pair<string, string>( "overworld", "north_shrine" ), MapPoint( 12, 16 ) },
    { pair<string, string>( "north_shrine", "overworld" ), MapPoint( 90, 8 ) },
    { pair<string, string>( "overworld", "kol" ), MapPoint( 28, 31 ) },
    { pair<string, string>( "kol", "overworld" ), MapPoint( 113, 17 ) }
};
#endif // MAPINFO_HPP_INCLUDED
