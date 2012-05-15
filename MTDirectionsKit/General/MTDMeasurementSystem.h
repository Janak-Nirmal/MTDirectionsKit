//
//  MTDMeasurementSystem.h
//  MTDirectionsKit
//
//  Created by Tretter Matthias
//  Copyright (c) 2012 Matthias Tretter (@myell0w). All rights reserved.
//


/**
 MTDirectionsKit can calculate it's distances using either Miles (U.S. System) or Kilometers (Metric System).
 MTDirectionsKit tries to be smart and sets the default used measurement system to the one set in the system locale.
 */
typedef enum {
    MTDMeasurementSystemMetric = 1,
    MTDMeasurementSystemUS
} MTDMeasurementSystem;


/** 
 This function returns the current used measurement system in MTDirectionsKit (kilometer or miles).
 
 @return the current used measurement system for calculating distances
 */
MTDMeasurementSystem MTDDirectionsGetMeasurementSystem(void);

/**
 This functions sets the current used measurement system in MTDirectionsKit
 
 @param measurementSystem the measurement system to compute distances
 */
void MTDDirectionsSetMeasurementSystem(MTDMeasurementSystem measurementSystem);

/**
 This functions returns a formatted distance string for the given distance and measurementSystem
 
 @param distance the distance in meters
 @param measurementSystem the measurementSystem to format for
 @return a formatted distance string
 */
NSString* MTDFormattedDistanceInMeasurementSystem(CLLocationDistance distance, MTDMeasurementSystem measurementSystem);