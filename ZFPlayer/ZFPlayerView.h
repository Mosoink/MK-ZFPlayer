//
//  ZFPlayerView.h
//
// Copyright (c) 2016年 任子丰 ( http://github.com/renzifeng )
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <UIKit/UIKit.h>


// 返回按钮的block
typedef void(^ZFPlayerGoBackBlock)(void);
// playerLayer的填充模式（默认：等比例填充，直到一个维度到达区域边界）
typedef NS_ENUM(NSInteger, ZFPlayerLayerGravity) {
     ZFPlayerLayerGravityResize,           // 非均匀模式。两个维度完全填充至整个视图区域
     ZFPlayerLayerGravityResizeAspect,     // 等比例填充，直到一个维度到达区域边界
     ZFPlayerLayerGravityResizeAspectFill  // 等比例填充，直到填充满整个视图区域，其中一个维度的部分区域会被裁剪
};

typedef NS_ENUM(NSInteger, ZFPlayerViewStyle) {
    ZFPlayerViewStyleDefault,
    ZFPlayerViewStyleLikeMPMoviewPlayerController
};

//播放器的几种状态
typedef NS_ENUM(NSInteger, ZFPlayerState) {
    ZFPlayerStatePause,      // 暂停播放
    ZFPlayerStateFailed,     // 播放失败
    ZFPlayerStateBuffering,  // 缓冲中
    ZFPlayerStatePlaying,    // 播放中
    ZFPlayerStateStopped,    // 停止播放
};

@class ZFPlayerView;
@protocol ZFPlayerViewDelegate <NSObject>

@optional
- (void)playerViewDidPlayFinished:(ZFPlayerView *)playerView;
- (void)playerView:(ZFPlayerView *)playerView stateDidChanged:(ZFPlayerState)state;
- (void)playerView:(ZFPlayerView *)playerView playingWithCurrentTime:(float)currentTime totalDuration:(float)totalDuration;

- (void)playerView:(ZFPlayerView *)playerView willHidenControlOverlayView:(BOOL)hiden animateWithDuration:(NSTimeInterval)duration;

@end

@class ZFPlayerControlView;
@interface ZFPlayerView : UIView

/** 控制层View */
@property (nonatomic, strong) ZFPlayerControlView *controlView;

/** 视频URL */
@property (nonatomic, strong) NSURL                *videoURL;
/** 视频URL的数组 */
@property (nonatomic, strong) NSArray              *videoURLArray;
/** 返回按钮Block */
@property (nonatomic, copy  ) ZFPlayerGoBackBlock  goBackBlock;
/** 设置playerLayer的填充模式 */
@property (nonatomic, assign) ZFPlayerLayerGravity playerLayerGravity;
/** 是否有下载功能(默认是关闭) */
@property (nonatomic, assign) BOOL                 hasDownload;

/** 是否支持锁屏 */
@property (nonatomic, assign) BOOL                 enableLock;
/** 左右互动手势 */
@property (nonatomic, assign) BOOL                 adjustPlaybackProgressWithPanGestureRecognizer;
/** 是否播放完成自动回到起始位置 */
@property (nonatomic, assign) BOOL                 enableAutoSeekToZeroOnFinished;


/** 切换分辨率传的字典(key:分辨率名称，value：分辨率url) */
@property (nonatomic, strong) NSDictionary         *resolutionDic;
/** 从xx秒开始播放视频跳转 */
@property (nonatomic, assign) NSInteger            seekTime;
/** 播发器的几种状态 */
@property (nonatomic, assign) ZFPlayerState       state;

@property (nonatomic, assign) ZFPlayerViewStyle    playerViewStyle;

@property (nonatomic, weak  ) id<ZFPlayerViewDelegate> delegate;

@property (nonatomic, copy  ) NSDictionary  *settingInfo;

// default CGFLOADT_MAX
@property (nonatomic) CGFloat maxDurationCanForward;

/**
 *  自动播放，默认不自动播放
 */
- (void)autoPlayTheVideo;
/**
 *  取消延时隐藏controlView的方法,在ViewController的delloc方法中调用
 *  用于解决：刚打开视频播放器，就关闭该页面，maskView的延时隐藏还未执行。
 */
- (void)cancelAutoFadeOutControlBar;

/**
 *  单例，用于列表cell上多个视频
 *
 *  @return ZFPlayer
 */
//+ (instancetype)sharedPlayerView;

/**
 *  player添加到cell上
 *
 *  @param cell 添加player的cellImageView
 */
- (void)addPlayerToCellImageView:(UIImageView *)imageView;

/**
 *  重置player
 */
- (void)resetPlayer;

/**
 *  在当前页面，设置新的Player的URL调用此方法
 */
- (void)resetToPlayNewURL;

/** 
 *  播放
 */
- (void)play;

/** 
  * 暂停 
 */
- (void)pause:(BOOL)force;


- (void)backButtonAction;

/**
 *  用于cell上播放player
 *
 *  @param videoURL  视频的URL
 *  @param tableView tableView
 *  @param indexPath indexPath 
 *  @param ImageViewTag ImageViewTag
 */
- (void)setVideoURL:(NSURL *)videoURL
      withTableView:(UITableView *)tableView
        AtIndexPath:(NSIndexPath *)indexPath
   withImageViewTag:(NSInteger)tag;


@end

UIKIT_EXTERN NSString * const ZFPlayerSettingInfoFailAlertText;
