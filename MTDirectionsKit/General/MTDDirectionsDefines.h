//
//  MTDDirectionsDefines.h
//  MTDirectionsKit
//
//  Created by Matthias Tretter
//  Copyright (c) 2012 Matthias Tretter (@myell0w). All rights reserved.
//


@class MTDDirectionsOverlay;
@class MTDMapView;


////////////////////////////////////////////////////////////////////////
#pragma mark - Defines
////////////////////////////////////////////////////////////////////////

// An invalid coordinate
#define MTDInvalidCLLocationCoordinate2D CLLocationCoordinate2DMake(-100., -100.)

// NSError-related constants
#define MTDDirectionsKitErrorDomain      @"MTDDirectionsKitErrorDomain"
#define MTDDirectionsKitDataKey          @"MTDDirectionsKitDataKey"


////////////////////////////////////////////////////////////////////////
#pragma mark - Typedefs
////////////////////////////////////////////////////////////////////////

// block that is passed to an instance of MTDDirectionsParser and reports success/failure of parsing
typedef void (^mtd_parser_block)(MTDDirectionsOverlay *overlay, NSError *error);

// block that is passed to an instance of MTDMapView and reports success/failure of direction retreival
typedef void (^mtd_directions_block)(MTDMapView *mapView, NSError *error);