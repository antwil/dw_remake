#include "Map.hpp"
#include "Constants.hpp"
#include "MapInfo.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

Map::Map( LTexture* spriteSheet, SDL_Renderer* renderer, SDL_Rect* camera )
{
    //Set the sprite sheet
    sprites = spriteSheet;

    mRenderer = renderer;
    mCamera = camera;

    //Initialize the rows and cols
    NUM_ROWS = NUM_COLS = -1;

    //Set the tile sprites clips
    //4 stone
    spriteClips[ TILE_FOUR_STONE ].x = 3;
    spriteClips[ TILE_FOUR_STONE ].y = 2;
    spriteClips[ TILE_FOUR_STONE ].w = 16;
    spriteClips[ TILE_FOUR_STONE ].h = 16;

    //Wall
    spriteClips[ TILE_STONE_WALL ].x = 20;
    spriteClips[ TILE_STONE_WALL ].y = 2;
    spriteClips[ TILE_STONE_WALL ].w = 16;
    spriteClips[ TILE_STONE_WALL ].h = 16;

    //Merchant Counter
    spriteClips[ TILE_COUNTER ].x = 37;
    spriteClips[ TILE_COUNTER ].y = 2;
    spriteClips[ TILE_COUNTER ].w = 16;
    spriteClips[ TILE_COUNTER ].h = 16;

    //Brick Floor
    spriteClips[ TILE_BRICK_FLOOR ].x = 54;
    spriteClips[ TILE_BRICK_FLOOR ].y = 2;
    spriteClips[ TILE_BRICK_FLOOR ].w = 16;
    spriteClips[ TILE_BRICK_FLOOR ].h = 16;

    //Treasure chest
    spriteClips[ TILE_CHEST ].x = 71;
    spriteClips[ TILE_CHEST ].y = 2;
    spriteClips[ TILE_CHEST ].w = 16;
    spriteClips[ TILE_CHEST ].h = 16;

    //Closed door
    spriteClips[ TILE_DOOR_CLOSED ].x = 88;
    spriteClips[ TILE_DOOR_CLOSED ].y = 2;
    spriteClips[ TILE_DOOR_CLOSED ].w = 16;
    spriteClips[ TILE_DOOR_CLOSED ].h = 16;

    //Down stairs
    spriteClips[ TILE_TOWN_STAIR_DOWN ].x = 105;
    spriteClips[ TILE_TOWN_STAIR_DOWN ].y = 2;
    spriteClips[ TILE_TOWN_STAIR_DOWN ].w = 16;
    spriteClips[ TILE_TOWN_STAIR_DOWN ].h = 16;

    //Up stairs
    spriteClips[ TILE_TOWN_STAIR_UP ].x = 122;
    spriteClips[ TILE_TOWN_STAIR_UP ].y = 2;
    spriteClips[ TILE_TOWN_STAIR_UP ].w = 16;
    spriteClips[ TILE_TOWN_STAIR_UP ].h = 16;

    //Security floor
    spriteClips[ TILE_SECURITY_FLOOR ].x = 139;
    spriteClips[ TILE_SECURITY_FLOOR ].y = 2;
    spriteClips[ TILE_SECURITY_FLOOR ].w = 16;
    spriteClips[ TILE_SECURITY_FLOOR ].h = 16;

    //Shop sign
    spriteClips[ TILE_ARMORER_SIGN ].x = 156;
    spriteClips[ TILE_ARMORER_SIGN ].y = 2;
    spriteClips[ TILE_ARMORER_SIGN ].w = 16;
    spriteClips[ TILE_ARMORER_SIGN ].h = 16;

    //Inn sign
    spriteClips[ TILE_INN_SIGN ].x = 173;
    spriteClips[ TILE_INN_SIGN ].y = 2;
    spriteClips[ TILE_INN_SIGN ].w = 16;
    spriteClips[ TILE_INN_SIGN ].h = 16;

    //Blank
    spriteClips[ TILE_BLANK ].x = 190;
    spriteClips[ TILE_BLANK ].y = 2;
    spriteClips[ TILE_BLANK ].w = 16;
    spriteClips[ TILE_BLANK ].h = 16;

    //Castle
    spriteClips[ TILE_CASTLE ].x = 3;
    spriteClips[ TILE_CASTLE ].y = 19;
    spriteClips[ TILE_CASTLE ].w = 16;
    spriteClips[ TILE_CASTLE ].h = 16;

    //Town
    spriteClips[ TILE_TOWN ].x = 20;
    spriteClips[ TILE_TOWN ].y = 19;
    spriteClips[ TILE_TOWN ].w = 16;
    spriteClips[ TILE_TOWN ].h = 16;

    //Grass
    spriteClips[ TILE_GRASS ].x = 37;
    spriteClips[ TILE_GRASS ].y = 19;
    spriteClips[ TILE_GRASS ].w = 16;
    spriteClips[ TILE_GRASS ].h = 16;

    //Trees
    spriteClips[ TILE_FOREST ].x = 54;
    spriteClips[ TILE_FOREST ].y = 19;
    spriteClips[ TILE_FOREST ].w = 16;
    spriteClips[ TILE_FOREST ].h = 16;

    //Hills
    spriteClips[ TILE_HILL ].x = 71;
    spriteClips[ TILE_HILL ].y = 19;
    spriteClips[ TILE_HILL ].w = 16;
    spriteClips[ TILE_HILL ].h = 16;

    //Mountain
    spriteClips[ TILE_MOUNTAIN ].x = 88;
    spriteClips[ TILE_MOUNTAIN ].y = 19;
    spriteClips[ TILE_MOUNTAIN ].w = 16;
    spriteClips[ TILE_MOUNTAIN ].h = 16;

    //Cave entrance
    spriteClips[ TILE_CAVE ].x = 105;
    spriteClips[ TILE_CAVE ].y = 19;
    spriteClips[ TILE_CAVE ].w = 16;
    spriteClips[ TILE_CAVE ].h = 16;

    //Grass stairs down
    spriteClips[ TILE_OUT_STAIR_DOWN ].x = 122;
    spriteClips[ TILE_OUT_STAIR_DOWN ].y = 19;
    spriteClips[ TILE_OUT_STAIR_DOWN ].w = 16;
    spriteClips[ TILE_OUT_STAIR_DOWN ].h = 16;

    //Desert
    spriteClips[ TILE_DESERT ].x = 139;
    spriteClips[ TILE_DESERT ].y = 19;
    spriteClips[ TILE_DESERT ].w = 16;
    spriteClips[ TILE_DESERT ].h = 16;

    //Swamp
    spriteClips[ TILE_SWAMP ].x = 156;
    spriteClips[ TILE_SWAMP ].y = 19;
    spriteClips[ TILE_SWAMP ].w = 16;
    spriteClips[ TILE_SWAMP ].h = 16;

    //Bridge
    spriteClips[ TILE_BRIDGE ].x = 173;
    spriteClips[ TILE_BRIDGE ].y = 19;
    spriteClips[ TILE_BRIDGE ].w = 16;
    spriteClips[ TILE_BRIDGE ].h = 16;

    //Princess
    spriteClips[ TILE_PRINCESS ].x = 190;
    spriteClips[ TILE_PRINCESS ].y = 19;
    spriteClips[ TILE_PRINCESS ].w = 16;
    spriteClips[ TILE_PRINCESS ].h = 16;

    //Ocean (no shores)
    spriteClips[ TILE_WATER ].x = 3;
    spriteClips[ TILE_WATER ].y = 36;
    spriteClips[ TILE_WATER ].w = 16;
    spriteClips[ TILE_WATER ].h = 16;

    //Bottom shore
    spriteClips[ TILE_SHORE_BOTTOM ].x = 20;
    spriteClips[ TILE_SHORE_BOTTOM ].y = 36;
    spriteClips[ TILE_SHORE_BOTTOM ].w = 16;
    spriteClips[ TILE_SHORE_BOTTOM ].h = 16;

    //Bottom-left shore
    spriteClips[ TILE_SHORE_BOTTOM_LEFT ].x = 37;
    spriteClips[ TILE_SHORE_BOTTOM_LEFT ].y = 36;
    spriteClips[ TILE_SHORE_BOTTOM_LEFT ].w = 16;
    spriteClips[ TILE_SHORE_BOTTOM_LEFT ].h = 16;

    //Left shore
    spriteClips[ TILE_SHORE_LEFT ].x = 54;
    spriteClips[ TILE_SHORE_LEFT ].y = 36;
    spriteClips[ TILE_SHORE_LEFT ].w = 16;
    spriteClips[ TILE_SHORE_LEFT ].h = 16;

    //Upper-left shore
    spriteClips[ TILE_SHORE_UP_LEFT ].x = 71;
    spriteClips[ TILE_SHORE_UP_LEFT ].y = 36;
    spriteClips[ TILE_SHORE_UP_LEFT ].w = 16;
    spriteClips[ TILE_SHORE_UP_LEFT ].h = 16;

    //Upper shore
    spriteClips[ TILE_SHORE_UP ].x = 88;
    spriteClips[ TILE_SHORE_UP ].y = 36;
    spriteClips[ TILE_SHORE_UP ].w = 16;
    spriteClips[ TILE_SHORE_UP ].h = 16;

    //Upper-right shore
    spriteClips[ TILE_SHORE_UP_RIGHT ].x = 105;
    spriteClips[ TILE_SHORE_UP_RIGHT ].y = 36;
    spriteClips[ TILE_SHORE_UP_RIGHT ].w = 16;
    spriteClips[ TILE_SHORE_UP_RIGHT ].h = 16;

    //Right shore
    spriteClips[ TILE_SHORE_RIGHT ].x = 122;
    spriteClips[ TILE_SHORE_RIGHT ].y = 36;
    spriteClips[ TILE_SHORE_RIGHT ].w = 16;
    spriteClips[ TILE_SHORE_RIGHT ].h = 16;

    //Bottom-right shore
    spriteClips[ TILE_SHORE_BOTTOM_RIGHT ].x = 139;
    spriteClips[ TILE_SHORE_BOTTOM_RIGHT ].y = 36;
    spriteClips[ TILE_SHORE_BOTTOM_RIGHT ].w = 16;
    spriteClips[ TILE_SHORE_BOTTOM_RIGHT ].h = 16;

    //Open to the right shore
    spriteClips[ TILE_SHORE_OPEN_RIGHT ].x = 156;
    spriteClips[ TILE_SHORE_OPEN_RIGHT ].y = 36;
    spriteClips[ TILE_SHORE_OPEN_RIGHT ].w = 16;
    spriteClips[ TILE_SHORE_OPEN_RIGHT ].h = 16;

    //Open to the right shore (uses same as open-to-right, just rotated 90 degrees)
    spriteClips[ TILE_SHORE_OPEN_BOTTOM ].x = 156;
    spriteClips[ TILE_SHORE_OPEN_BOTTOM ].y = 36;
    spriteClips[ TILE_SHORE_OPEN_BOTTOM ].w = 16;
    spriteClips[ TILE_SHORE_OPEN_BOTTOM ].h = 16;

    //Open to the left shore
    spriteClips[ TILE_SHORE_OPEN_LEFT ].x = 173;
    spriteClips[ TILE_SHORE_OPEN_LEFT ].y = 36;
    spriteClips[ TILE_SHORE_OPEN_LEFT ].w = 16;
    spriteClips[ TILE_SHORE_OPEN_LEFT ].h = 16;

    //Open to the left shore (uses same as open-to-left, just rotated 90 degrees)
    spriteClips[ TILE_SHORE_OPEN_TOP ].x = 173;
    spriteClips[ TILE_SHORE_OPEN_TOP ].y = 36;
    spriteClips[ TILE_SHORE_OPEN_TOP ].w = 16;
    spriteClips[ TILE_SHORE_OPEN_TOP ].h = 16;

    //Up-down shore
    spriteClips[ TILE_SHORE_UP_DOWN ].x = 190;
    spriteClips[ TILE_SHORE_UP_DOWN ].y = 36;
    spriteClips[ TILE_SHORE_UP_DOWN ].w = 16;
    spriteClips[ TILE_SHORE_UP_DOWN ].h = 16;

    //Left-right shore (uses same as up-down, just rotated 90 degrees)
    spriteClips[ TILE_SHORE_LEFT_RIGHT ].x = 190;
    spriteClips[ TILE_SHORE_LEFT_RIGHT ].y = 36;
    spriteClips[ TILE_SHORE_LEFT_RIGHT ].w = 16;
    spriteClips[ TILE_SHORE_LEFT_RIGHT ].h = 16;
}

Map::~Map()
{
    //freeTiles();
}

/*
void Map::freeTiles()
{
    for( int row = 0; row < NUM_ROWS; ++row )
    {
        delete tiles[ row ];
        tiles[ row ] = NULL;
    }

    delete tiles;
    tiles = NULL;
}
*/

bool Map::validateMap( std::string mapFile )
{
    //Open the map
    std::ifstream map;
    map.open( mapFile, std::ios::in );
    if( !map )
    {
        printf( "Unable to load map file %s!\n", mapFile.c_str() );
        return false;
    }

    int MAX_COL = -1;

    //Current row and col;
    int row = 0, col = 0;
    std::string line;
    while( std::getline( map, line ) )
    {
        col = 0;

        std::istringstream tilesString( line );
        int tileType;
        while( tilesString >> tileType )
        {
            if( tileType >= NUM_TILES || tileType < 0 )
            {
                printf( "Tile in position (%d, %d) in map %s is not a valid tile type!\n", row, col, mapFile.c_str() );
                return false;
            }

            col++;
        }

        //All columns (and rows, but this check will subsume row check)
        //should be the same length, if not, report error
        if( MAX_COL == -1 )
        {
            MAX_COL = col;
        }
        else if( col != MAX_COL )
        {
            printf( "Map %s is not formatted correctly! Error likely in row %d.\n", mapFile.c_str(), row );
            return false;
        }

        row++;
    }

    map.close();

    NUM_ROWS = row;
    NUM_COLS = col;

    MAP_WIDTH = NUM_COLS * Tile::TILE_WIDTH;
    MAP_HEIGHT = NUM_ROWS * Tile::TILE_HEIGHT;

    return true;
}

bool Map::loadMap( std::string mapName )
{
    tiles.clear();
    //tiles.swap( std::vector< std::vector< Tile > >() );
    std::string mapFile = "res/" + mapName + ".map";

    if( !validateMap( mapFile ) )
    {
        printf( "Map %s is invalid!\n", mapFile.c_str() );
        return false;
    }

    //Open the map
    std::ifstream map;
    map.open( mapFile, std::ios::in );
    if( !map )
    {
        printf( "Unable to load map file %s!\n", mapFile.c_str() );
        return false;
    }

    //Current row and col;
    int row = 0, col = 0;
    std::string line;
    while( std::getline( map, line ) )
    {
        col = 0;
        std::vector< Tile > tileRow;

        std::istringstream tilesString( line );
        int tileType;
        while( tilesString >> tileType )
        {
            tileRow.push_back( Tile( tileType ) );
            col++;
        }


        tiles.push_back( tileRow );
        row++;
    }

    map.close();

    this->mapName = mapName;

    loadMapInfo( mapName );

    return true;
}

void Map::render( uint8_t frame )
{
    //Row and column of first tile we should render based on
    //where the camera is currently positioned
    int row = -1, col = -1;
    row = mCamera->y / Tile::TILE_HEIGHT;
    col = mCamera->x / Tile::TILE_WIDTH;

    //std::cout << "Starting render" << std::endl;
    for( int i = row; i <= row + (mCamera->h / Tile::TILE_HEIGHT); i++ )
    {
        for( int j = col; j <= col + (mCamera->w / Tile::TILE_WIDTH) + 1; j++ )
        {
            int tileX = (j * Tile::TILE_WIDTH) - mCamera->x;
            int tileY = (i * Tile::TILE_HEIGHT) - mCamera->y;

            //int type = tiles[ i ][ j ].getType();
            uint8_t type = getTile( i, j ).getType();
            double angle = 0.0;
            if( rotateTile( type ) )
            {
                angle = 90.0;
            }

            sprites->render( tileX, tileY, mRenderer, angle, &spriteClips[ type ] );
        }
    }
}

void Map::loadMapInfo( std::string mapName )
{
    if( mapName == "overworld" )
    {
        exits = overworld_exits;
        treasures = overworld_treasure;
    }
    else if( mapName == "brecconary" )
    {
        exits = brecconary_exits;
        treasures = brecconary_treasure;
    }
    else if( mapName == "garinham" )
    {
        exits = garinham_exits;
        treasures = garinham_treasure;
    }
    else if( mapName == "north_shrine" )
    {
        exits = north_shrine_exits;
        treasures = north_shrine_treasure;
    }
    else if( mapName == "kol" )
    {
        exits = kol_exits;
        treasures = kol_treasure;
    }
}

bool Map::rotateTile( const uint8_t tileType )
{
    switch( tileType )
    {
        case TILE_SHORE_LEFT_RIGHT:
        case TILE_SHORE_OPEN_BOTTOM:
        case TILE_SHORE_OPEN_TOP:
            return true;
        default:
            return false;
    }
}

void Map::checkLocationEvent( Player* mPlayer )
{
    int pX = mPlayer->getXTile();
    int pY = mPlayer->getYTile();

    if( exits.count( MapPoint( pX, pY ) ) )
    {
        std::string currMap = mapName;
        std::string nextMap = exits.at( MapPoint( pX, pY ) );
        loadMap( nextMap );
        MapPoint loc = locations.at( std::pair<std::string, std::string>( currMap, nextMap ) );
        mPlayer->setLocation( loc.first, loc.second );
    }

}

bool Map::openDoor( int xPos, int yPos, uint8_t playerDir )
{
    return false;
}

bool Map::getItem( int xPos, int yPos )
{
    if( treasures.count( MapPoint( xPos, yPos ) ) )
    {
        std::pair<int, std::string> itemInfo = treasures.at( MapPoint( xPos, yPos ) );
        std::string item = itemInfo.second;
        switch ( itemInfo.first )
        {
            case TREASURE_CHEST:
                printf( "Found treasure in chest: %s\n", item.c_str() );
                break;
            case HIDDEN_ITEM:
                printf( "Found hidden treasure: %s\n", item.c_str() );
                break;
        }

        return true;
    }

    return false;
}

Tile Map::getTile(int row, int col)
{
    return tiles.at( row ).at( col );
}

int Map::getNumRows()
{
    return NUM_ROWS;
}

int Map::getNumCols()
{
    return NUM_COLS;
}

int Map::getWidth()
{
    return MAP_WIDTH;
}

int Map::getHeight()
{
    return MAP_HEIGHT;
}
