//
//  MTDAddress.h
//  MTDirectionsKit
//
//  Created by Matthias Tretter
//  Copyright (c) 2012 Matthias Tretter (@myell0w). All rights reserved.
//


/**
 This enum can be used to generate a specific string-representation of a normalised address object.
 */
typedef enum {
    MTDAddressFieldCountry          = 1,
    MTDAddressFieldCounty           = 1 << 1,
    MTDAddressFieldPostalCode       = 1 << 2,
    MTDAddressFieldState            = 1 << 3,
    MTDAddressFieldCity             = 1 << 4,
    MTDAddressFieldStreet           = 1 << 5
} MTDAddressField;


/**
 MTDAddress represents the human readable address description of a waypoint.
 It can either be initialized and read in a normalized form (separate fields
 for country, county, postalCode etc.) or with a single string. Currently a 
 single string doens't get parsed and normalised.
 */
@interface MTDAddress : NSObject

/******************************************
 @name Address data
 ******************************************/

/** the country of the address or nil, if this address isn't normalised */
@property (nonatomic, readonly) NSString *country;
/** the county of the address or nil, if this address isn't normalised */
@property (nonatomic, readonly) NSString *county;
/** the postal code of the address as string or nil, if this address isn't normalised */
@property (nonatomic, readonly) NSString *postalCode;
/** the state of the address or nil, if this address isn't normalised */
@property (nonatomic, readonly) NSString *state;
/** the city of the address or nil, if this address isn't normalised */
@property (nonatomic, readonly) NSString *city;
/** the street name of the address or nil, if this address isn't normalised */
@property (nonatomic, readonly) NSString *street;

/** The full address string, concatenated via "," */
@property (nonatomic, readonly) NSString *fullAddress;

/** 
 This flag indicates whether this address is normalised and the
 separate properties for country, county etc. return valid data
 */
@property (nonatomic, readonly, getter = isNormalised) BOOL normalised;


/******************************************
 @name Initializer
 ******************************************/

/**
 Initializes an address object with a single string. The resulting address object
 is not normalized.
 
 @param addressString a single string-representation of the address
 @return a non-normalized address object
 @see initWithCountry:county:postalCode:state:city:street:
 */
- (id)initWithAddressString:(NSString *)addressString;

/**
 Initializes an address object with normalized data, the resulting address object is normalised.
 
 @param country the country of the address
 @param county the county of the address
 @param postalCode the postal code of the address
 @param state the state of the address
 @param city the city of the address
 @param street the street of the address
 @return a normalised address object
 @see initWithAddressString:
 */
- (id)initWithCountry:(NSString *)country
               county:(NSString *)county
           postalCode:(NSString *)postalCode
                state:(NSString *)state
                 city:(NSString *)city
               street:(NSString *)street;


/******************************************
 @name String representation
 ******************************************/

/**
 On normalised address objects this method can be used to create a description of the
 address only including the specified address fields (via bitmask). Valid address fields are specified
 in the enum MTDAddressField:

 - MTDAddressFieldCountry
 - MTDAddressFieldCounty
 - MTDAddressFieldPostalCode
 - MTDAddressFieldState
 - MTDAddressFieldCity
 - MTDAddressFieldStreet
 
 On non-normalized string objects this method just returns the fullAddress string.
 
 @param addressFieldMask a bitmaks including the address fields to include in the description,
        e.g. MTDAddressFieldCountry | MTDAddressFieldCity
 
 @return a string representation of the address including the specified fields
 */
- (NSString *)descriptionWithAddressFields:(NSUInteger)addressFieldMask;

@end
