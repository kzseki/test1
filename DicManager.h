//
//  DicManager.h
//  E-Assist
//
//  Created by K.S on 07/02/20.
//  Copyright 2007 K.S. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ExampleSearcher.h"

// add thie line by KS

@interface DicManager : NSObject
{
	BOOL				_serviceMode;
	BOOL				_headingOption;
	BOOL				_onlyHeading;
	unsigned char 		*_rexString;
	
	NSMutableArray		*_dicList;
	NSMutableArray		*_dicNameList;
	
	NSPopUpButton		*_dicSelector;
	NSPopUpButton		*_searchModeSelector;
	id					_currDic;
	
	int					_nResults;	// num. of results
	int					_currDicIndex;
	int					_currSearchMode;
	int					_currSearchTarget;
	NSMutableArray		*_searchResultHolder;
	
	NSTextView			*_dtextView;
	float				_headFontSize;
	float				_descFontSize;
	NSFont				*_headerFont;
	NSFont				*_descFont;
	NSRange				_headerRange;
	NSRange				_descRange;
	NSRange				_descWOExampleRange;
	
	NSString			*_fileLinkMark;
	NSString			*_currHeading;
	
	ExampleSearcher		*_exampleSearcher;
	
	NSMutableArray		*_rexObjs;
}

+ (id)sharedDicManager;
- (int)initWithDicDirectory:(NSString *)dicPath;
- (void)setUpPDic:(NSString *)dicName directory:(NSString *)dicPath fileName:(NSString *)fname;
- (void)changeCurrDictionary:(id)sender;
- (SEL)getHandler;
- (void)setDicSelector:(NSPopUpButton *)popup;
- (void)setupDicSelector;

- (void)setModeSelector:(NSPopUpButton *)popup;

- (int)searchWord:(NSString *)words;
- (int)searchText:(NSString *)words withHeading:(BOOL)headSearch;
- (int)searchService:(NSString *)words;
- (int)searchExample:(NSString *)words;

- (void)setTextView:(id)textView;
- (void)changeTextSize:(int)deltaPoint;
- (void)showTextAtIndex:(int)rowIndex;
- (void)clearText;
- (NSString *)getCurrentHeading;

@end
