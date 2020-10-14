//
//  CATClearProjectTool.h
//  CATClearProjectTool
//
//  Created by CatchZeng on 16/1/1.
//  Copyright © 2015年 catch. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CATClearProjectToolDelegate <NSObject>

@required
-(void)searchAllClassesSuccess:(NSMutableDictionary *)dic;
-(void)searchUnUsedClassesSuccess:(NSMutableDictionary *)dic;
-(void)clearUnUsedClassesSuccess:(NSMutableDictionary *)dic;

@optional
-(void)searchAllClassesError:(NSError *)error;
-(void)searchUnUsedClassesError:(NSError *)error;
-(void)clearUnUsedClassesError:(NSError *)error;

@end

@interface CATClearProjectTool : NSObject

@property (nonatomic,weak) id<CATClearProjectToolDelegate> delegate;

/// set filter classes. 设置过滤类
/// @param array filter classes name 过滤类名
-(void)setFliterClasses:(NSArray *)array;

/// start search unused classes 开始搜索未使用类
/// @param path  .xcodeproj file path
-(void)startSearchWithXcodeprojFilePath:(NSString *)path;

/// clear unUsedClasses file and meta data in project file 清除项目文件中的未使用的类文件和元数据
-(void)clearFileAndMetaData;

@end
