//
//  MTDMapView.h
//  MTDirectionsKit
//
//  Created by Matthias Tretter
//  Copyright (c) 2012 Matthias Tretter (@myell0w). All rights reserved.
//


#import "MTDDirectionsRouteType.h"
#import "MTDDirectionsDisplayType.h"
#import "MTDDirectionsDefines.h"


@class MTDDirectionsOverlay;
@class MTDDirectionsOverlayView;
@protocol MTDDirectionsDelegate;


/**
 An MTDMapView instance provides functionality to show directions directly on top of the MapView inside your App.
 MTDMapView is a subclass of MKMapView and therefore uses Apple's standard way of displaying map data, which we all
 know and love. Currently this means that Google Maps is used as a backend, let's see if this is still true once
 iOS 6 will be released :-)
 
 Sample usage:
 
    MTDMapView *_mapView = [[MTDMapView alloc] initWithFrame:self.view.bounds];
    _mapView.directionsDelegate = self;
 
    [_mapView loadDirectionsFrom:CLLocationCoordinate2DMake(51.38713, -1.0316)
                             to:CLLocationCoordinate2DMake(51.4554, -0.9742)
                      routeType:MTDDirectionsRouteTypeFastestDriving
           zoomToShowDirections:YES];
 
 */
@interface MTDMapView : MKMapView

/******************************************
 @name Delegate
 ******************************************/

/**
 The receiver's directionsDelegate
 */
@property (nonatomic, unsafe_unretained) id<MTDDirectionsDelegate> directionsDelegate;

/******************************************
 @name Directions
 ******************************************/

/** 
 The current active direction overlay. Setting the directions overlay automatically removes
 the previous directionsOverlay (if existing) and adds the new directionsOverlay as an overlay
 to the underlying MKMapView.
 */
@property (nonatomic, strong) MTDDirectionsOverlay *directionsOverlay;

/** 
 The current active direction overlay view. This property is only set, if there is a current
 active directionsOverlay and the mapView already requested an an instance of MKOverlayView
 for the specified directionsOverlay.
 */
@property (nonatomic, strong, readonly) MTDDirectionsOverlayView *directionsOverlayView;

/** 
 The current display type of the directions overlay. You can change the way the directions
 are shown on top of your instance of MTDMapView by changing the property. A change results
 in a re-draw of the overlay.
 */
@property (nonatomic, assign) MTDDirectionsDisplayType directionsDisplayType;

/** the starting coordinate of the directions of the currently displayed overlay */
@property (nonatomic, readonly) CLLocationCoordinate2D fromCoordinate;
/** the end coordinate of the directions of the currently displayed overlay */
@property (nonatomic, readonly) CLLocationCoordinate2D toCoordinate;
/** the total distance of the directions of the currently displayed overlay, by using all waypoints */
@property (nonatomic, readonly) CLLocationDistance distance;
/** the type of travelling used to compute the directions of the currently displayed overlay */
@property (nonatomic, readonly) MTDDirectionsRouteType routeType;

/**
 Starts a request and loads the directions between the specified coordinates.
 When the request is finished the directionsOverlay gets set on the MapView and
 the region gets zoomed (animated) to show the whole overlay, if the flag zoomToShowDirections is set.
 
 @param fromCoordinate the start point of the direction
 @param toCoordinate the end point of the direction
 @param routeType the type of the route requested, e.g. pedestrian, cycling, fastest driving
 @param zoomToShowDirections flag whether the mapView gets zoomed to show the overlay (gets zoomed animated)

 @see cancelLoadOfDirections
 */
- (void)loadDirectionsFrom:(CLLocationCoordinate2D)fromCoordinate
                        to:(CLLocationCoordinate2D)toCoordinate
                 routeType:(MTDDirectionsRouteType)routeType
      zoomToShowDirections:(BOOL)zoomToShowDirections;

/**
 Cancels a possible ongoing request for loading directions.
 Does nothing if there is no request active.
 
  @see loadDirectionsFrom:to:routeType:zoomToShowDirections:
 */
- (void)cancelLoadOfDirections;

/**
 Removes the currenty displayed directionsOverlay view from the MapView,
 if one exists. Does nothing otherwise.
 */
- (void)removeDirectionsOverlay;

/******************************************
 @name Inter-App
 ******************************************/

/**
 If directionsOverlay is currently set, this method opens the same directions
 that are currently displayed on top of your MTDMapView in the built-in Maps.app
 of the user's device. Does nothing otherwise.
 */
- (void)openDirectionsInMapApp;

/******************************************
 @name Region
 ******************************************/

/**
 Sets the region of the MapView to show the whole directionsOverlay at once.
 
 @param animated flag whether the region gets changed animated, or not
 */
- (void)setRegionToShowDirectionsAnimated:(BOOL)animated;


@end
