//
//  DicManager.m
//  E-Assist
//
//  Created by K.S on 07/02/20.
//  Copyright 2007 K.S. All rights reserved.
//

#import "Global.h"
#import "DicManager.h"
#import "PDic.h"
#import "PDicSearchResult.h"
#import "KSRegularExpression.h"

#include "PDicSpec.h"
#include "util.h"

@implementation DicManager

static id dicManager = nil;

+ (id)sharedDicManager
{
	return dicManager;
}

- (id)init
{
	if (self = [super init])
	{
		char *fileLinkMark = "◆file:";
		_fileLinkMark = [NSString stringWithUTF8String:fileLinkMark];
		[_fileLinkMark retain];
		
		dicManager = self;
		_serviceMode = NO;
		_dicList = [[NSMutableArray alloc] init];
		_dicNameList = [[NSMutableArray alloc] init];
		_searchResultHolder = [[NSMutableArray alloc] init];
		_nResults = 0;
		_currDicIndex = -1;
		_currHeading = nil;
		_exampleSearcher = [[ExampleSearcher alloc] init];
		_rexObjs = nil;
		_rexString = NULL;
	}
	return self;
}
