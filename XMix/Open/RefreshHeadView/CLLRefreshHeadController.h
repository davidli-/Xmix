//
//  CLLRefreshHeadController.h
//  RefreshLoadView
//
//  Created by chuliangliang on 14-6-12.
//  Copyright (c) 2014年 aikaola. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, CLLRefreshState) {
    CLLRefreshStatePulling   = 0,
    CLLRefreshStateNormal    = 1,
    CLLRefreshStateLoading   = 2,
    CLLRefreshStateStopped   = 3,
};

typedef NS_ENUM(NSInteger, CLLLoadMoreState) {
    CLLLoadMoreStateNormal    = 10,
    CLLLoadMoreStateLoading   = 11,
    CLLLoadMoreStateStopped   = 12,
};

typedef NS_ENUM(NSInteger, CLLRefreshViewLayerType) {
    CLLRefreshViewLayerTypeOnScrollViews = 0,
    CLLRefreshViewLayerTypeOnSuperView = 1,
};


@protocol CLLRefreshHeadControllerDelegate <NSObject>
@required /* 必须协议*/
//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////--下拉刷新相关方法--//////////////////////////////////////////////
/**
 * 1 、下拉开始刷新
 *
 **/
- (void)shouldStartRefreshHeader;

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////--上拉加载更多相关方法--///////////////////////////////////////////

/**
 * 2、上拉加载更多
 **/
- (void)shouldStartLoadFooter;

@optional /*可选协议*/
/**
 *  1、标识下拉刷新是UIScrollView的子view，还是UIScrollView父view的子view
 *
 *  @return 如果没有实现该delegate方法，默认是scrollView的子View，为CLLRefreshViewLayerTypeOnScrollViews
 **/
- (CLLRefreshViewLayerType)refreshViewLayerType;

/**
 *  2、UIScrollView的控制器是否保留iOS7新的特性，意思是：tablView的内容是否可以显示导航条后面
 *
 *  @return 如果不实现该delegate方法，默认是不支持的
 **/
- (BOOL)keepiOS7NewApiCharacter;


/**
 * 是否显示 下拉刷新视图
 * @return 如果不实现该delegate方法，默认是没有更多
 **/

- (BOOL)hasRefreshHeaderView;

/**
 * 3、是否显示 上拉更多视图
 * @return 如果不实现该delegate方法，默认是没有更多
 **/
- (BOOL)hasRefreshFooterView;
@end


#import <Foundation/Foundation.h>
#import "CLLRefreshFooterView.h"
#import "CLLRefreshHeadView.h"


@interface CLLRefreshHeadController : NSObject

@property (nonatomic,strong)CLLRefreshHeadView *refreshHeadView;
@property (nonatomic,strong)CLLRefreshFooterView *refreshFooterView;

@property (nonatomic, assign) CGFloat refreshInsetTop;
@property (nonatomic, assign) CGFloat refreshInsetBottom;


- (id)initWithScrollView:(UIScrollView *)scrollView topInset:(CGFloat)topInset bottomInset:(CGFloat)bottomInset inFooter:(BOOL)inFooter viewDelegate:(id <CLLRefreshHeadControllerDelegate>)delegate;

//创建Header Footer
- (CLLRefreshHeadView *)createHeaderview;
- (CLLRefreshFooterView *)createFooterview;

- (void)setup;

//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////--下拉刷新相关方法--//////////////////////////////////////////////
/**
 *  外部手动启动下拉刷新的方法，例如 第一次进来 tableview自动下拉刷新
 */
- (void)CLstartRefreshHeader;

/**
 *  外部手动启动上滑加载的方法，例如 第一次进来 tableview自动下拉刷新
 */
- (void)CLstartRefreshFooter;

/**
 *  停止下拉刷新的方法
 */
- (void)CLfinishRefreshHeader;

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////--上拉加载更多相关方法--///////////////////////////////////////////

/**
 *  停止上拉加载更多的方法
 */
- (void)CLfinishRefreshFooter;

@end
