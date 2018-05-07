// Objective-C API for talking to github.com/centrifugal/centrifuge-mobile Go package.
//   gobind -lang=objc github.com/centrifugal/centrifuge-mobile
//
// File is generated by gobind. Do not edit.

#ifndef __Centrifuge_H__
#define __Centrifuge_H__

@import Foundation;
#include "Universe.objc.h"


@class CentrifugeClient;
@class CentrifugeClientInfo;
@class CentrifugeConfig;
@class CentrifugeConnectEvent;
@class CentrifugeCredentials;
@class CentrifugeDisconnectEvent;
@class CentrifugeErrorEvent;
@class CentrifugeEventHub;
@class CentrifugeHistoryData;
@class CentrifugeJoinEvent;
@class CentrifugeLeaveEvent;
@class CentrifugeMessageEvent;
@class CentrifugePresenceData;
@class CentrifugePrivateSign;
@class CentrifugePrivateSubEvent;
@class CentrifugePublication;
@class CentrifugePublishEvent;
@class CentrifugeSubscribeErrorEvent;
@class CentrifugeSubscribeSuccessEvent;
@class CentrifugeSubscription;
@class CentrifugeSubscriptionEventHub;
@class CentrifugeUnsubscribeEvent;
@protocol CentrifugeConnectHandler;
@class CentrifugeConnectHandler;
@protocol CentrifugeDisconnectHandler;
@class CentrifugeDisconnectHandler;
@protocol CentrifugeErrorHandler;
@class CentrifugeErrorHandler;
@protocol CentrifugeJoinHandler;
@class CentrifugeJoinHandler;
@protocol CentrifugeLeaveHandler;
@class CentrifugeLeaveHandler;
@protocol CentrifugeMessageHandler;
@class CentrifugeMessageHandler;
@protocol CentrifugePrivateSubHandler;
@class CentrifugePrivateSubHandler;
@protocol CentrifugePublishHandler;
@class CentrifugePublishHandler;
@protocol CentrifugeRefreshHandler;
@class CentrifugeRefreshHandler;
@protocol CentrifugeSubscribeErrorHandler;
@class CentrifugeSubscribeErrorHandler;
@protocol CentrifugeSubscribeSuccessHandler;
@class CentrifugeSubscribeSuccessHandler;
@protocol CentrifugeUnsubscribeHandler;
@class CentrifugeUnsubscribeHandler;

@protocol CentrifugeConnectHandler <NSObject>
- (void)onConnect:(CentrifugeClient*)p0 p1:(CentrifugeConnectEvent*)p1;
@end

@protocol CentrifugeDisconnectHandler <NSObject>
- (void)onDisconnect:(CentrifugeClient*)p0 p1:(CentrifugeDisconnectEvent*)p1;
@end

@protocol CentrifugeErrorHandler <NSObject>
- (void)onError:(CentrifugeClient*)p0 p1:(CentrifugeErrorEvent*)p1;
@end

@protocol CentrifugeJoinHandler <NSObject>
- (void)onJoin:(CentrifugeSubscription*)p0 p1:(CentrifugeJoinEvent*)p1;
@end

@protocol CentrifugeLeaveHandler <NSObject>
- (void)onLeave:(CentrifugeSubscription*)p0 p1:(CentrifugeLeaveEvent*)p1;
@end

@protocol CentrifugeMessageHandler <NSObject>
- (void)onMessage:(CentrifugeClient*)p0 p1:(CentrifugeMessageEvent*)p1;
@end

@protocol CentrifugePrivateSubHandler <NSObject>
- (CentrifugePrivateSign*)onPrivateSub:(CentrifugeClient*)p0 p1:(CentrifugePrivateSubEvent*)p1 error:(NSError**)error;
@end

@protocol CentrifugePublishHandler <NSObject>
- (void)onPublish:(CentrifugeSubscription*)p0 p1:(CentrifugePublishEvent*)p1;
@end

@protocol CentrifugeRefreshHandler <NSObject>
- (CentrifugeCredentials*)onRefresh:(CentrifugeClient*)p0 error:(NSError**)error;
@end

@protocol CentrifugeSubscribeErrorHandler <NSObject>
- (void)onSubscribeError:(CentrifugeSubscription*)p0 p1:(CentrifugeSubscribeErrorEvent*)p1;
@end

@protocol CentrifugeSubscribeSuccessHandler <NSObject>
- (void)onSubscribeSuccess:(CentrifugeSubscription*)p0 p1:(CentrifugeSubscribeSuccessEvent*)p1;
@end

@protocol CentrifugeUnsubscribeHandler <NSObject>
- (void)onUnsubscribe:(CentrifugeSubscription*)p0 p1:(CentrifugeUnsubscribeEvent*)p1;
@end

@interface CentrifugeClient : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (BOOL)close:(NSError**)error;
- (BOOL)connect:(NSError**)error;
- (BOOL)disconnect:(NSError**)error;
- (NSData*)rpc:(NSData*)data error:(NSError**)error;
- (BOOL)send:(NSData*)data error:(NSError**)error;
- (void)setConnectData:(NSData*)data;
- (void)setCredentials:(CentrifugeCredentials*)creds;
- (CentrifugeSubscription*)subscribe:(NSString*)channel events:(CentrifugeSubscriptionEventHub*)events error:(NSError**)error;
- (CentrifugeSubscription*)subscribeSync:(NSString*)channel events:(CentrifugeSubscriptionEventHub*)events error:(NSError**)error;
@end

@interface CentrifugeClientInfo : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)client;
- (void)setClient:(NSString*)v;
- (NSString*)user;
- (void)setUser:(NSString*)v;
- (NSData*)connInfo;
- (void)setConnInfo:(NSData*)v;
- (NSData*)chanInfo;
- (void)setChanInfo:(NSData*)v;
@end

@interface CentrifugeConfig : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (long)readTimeoutMilliseconds;
- (void)setReadTimeoutMilliseconds:(long)v;
- (long)writeTimeoutMilliseconds;
- (void)setWriteTimeoutMilliseconds:(long)v;
- (long)pingIntervalMilliseconds;
- (void)setPingIntervalMilliseconds:(long)v;
- (NSString*)privateChannelPrefix;
- (void)setPrivateChannelPrefix:(NSString*)v;
@end

@interface CentrifugeConnectEvent : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)clientID;
- (void)setClientID:(NSString*)v;
- (NSString*)version;
- (void)setVersion:(NSString*)v;
- (NSData*)data;
- (void)setData:(NSData*)v;
@end

@interface CentrifugeCredentials : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init:(NSString*)user exp:(NSString*)exp info:(NSString*)info sign:(NSString*)sign;
- (NSString*)user;
- (void)setUser:(NSString*)v;
- (NSString*)exp;
- (void)setExp:(NSString*)v;
- (NSString*)info;
- (void)setInfo:(NSString*)v;
- (NSString*)sign;
- (void)setSign:(NSString*)v;
@end

@interface CentrifugeDisconnectEvent : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)reason;
- (void)setReason:(NSString*)v;
- (BOOL)reconnect;
- (void)setReconnect:(BOOL)v;
@end

@interface CentrifugeErrorEvent : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)message;
- (void)setMessage:(NSString*)v;
@end

@interface CentrifugeEventHub : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (void)onConnect:(id<CentrifugeConnectHandler>)handler;
- (void)onDisconnect:(id<CentrifugeDisconnectHandler>)handler;
- (void)onError:(id<CentrifugeErrorHandler>)handler;
- (void)onMessage:(id<CentrifugeMessageHandler>)handler;
- (void)onPrivateSub:(id<CentrifugePrivateSubHandler>)handler;
- (void)onRefresh:(id<CentrifugeRefreshHandler>)handler;
@end

@interface CentrifugeHistoryData : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (CentrifugePublication*)itemAt:(long)i;
- (long)numItems;
@end

@interface CentrifugeJoinEvent : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)client;
- (void)setClient:(NSString*)v;
- (NSString*)user;
- (void)setUser:(NSString*)v;
- (NSData*)connInfo;
- (void)setConnInfo:(NSData*)v;
- (NSData*)chanInfo;
- (void)setChanInfo:(NSData*)v;
@end

@interface CentrifugeLeaveEvent : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)client;
- (void)setClient:(NSString*)v;
- (NSString*)user;
- (void)setUser:(NSString*)v;
- (NSData*)connInfo;
- (void)setConnInfo:(NSData*)v;
- (NSData*)chanInfo;
- (void)setChanInfo:(NSData*)v;
@end

@interface CentrifugeMessageEvent : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSData*)data;
- (void)setData:(NSData*)v;
@end

@interface CentrifugePresenceData : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (CentrifugeClientInfo*)itemAt:(long)i;
- (long)numItems;
@end

@interface CentrifugePrivateSign : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)sign;
- (void)setSign:(NSString*)v;
- (NSString*)info;
- (void)setInfo:(NSString*)v;
@end

@interface CentrifugePrivateSubEvent : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)clientID;
- (void)setClientID:(NSString*)v;
- (NSString*)channel;
- (void)setChannel:(NSString*)v;
@end

@interface CentrifugePublication : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)uid;
- (void)setUID:(NSString*)v;
- (NSData*)data;
- (void)setData:(NSData*)v;
- (CentrifugeClientInfo*)info;
- (void)setInfo:(CentrifugeClientInfo*)v;
@end

@interface CentrifugePublishEvent : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)uid;
- (void)setUID:(NSString*)v;
- (NSData*)data;
- (void)setData:(NSData*)v;
- (CentrifugeClientInfo*)info;
- (void)setInfo:(CentrifugeClientInfo*)v;
@end

@interface CentrifugeSubscribeErrorEvent : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)error;
- (void)setError:(NSString*)v;
@end

@interface CentrifugeSubscribeSuccessEvent : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (BOOL)resubscribed;
- (void)setResubscribed:(BOOL)v;
- (BOOL)recovered;
- (void)setRecovered:(BOOL)v;
@end

@interface CentrifugeSubscription : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)channel;
- (CentrifugeHistoryData*)history:(NSError**)error;
- (CentrifugePresenceData*)presence:(NSError**)error;
- (BOOL)publish:(NSData*)data error:(NSError**)error;
- (BOOL)subscribe:(NSError**)error;
- (BOOL)unsubscribe:(NSError**)error;
@end

@interface CentrifugeSubscriptionEventHub : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (void)onJoin:(id<CentrifugeJoinHandler>)handler;
- (void)onLeave:(id<CentrifugeLeaveHandler>)handler;
- (void)onPublish:(id<CentrifugePublishHandler>)handler;
- (void)onSubscribeError:(id<CentrifugeSubscribeErrorHandler>)handler;
- (void)onSubscribeSuccess:(id<CentrifugeSubscribeSuccessHandler>)handler;
- (void)onUnsubscribe:(id<CentrifugeUnsubscribeHandler>)handler;
@end

@interface CentrifugeUnsubscribeEvent : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
@end

FOUNDATION_EXPORT const int64_t CentrifugeDefaultPingIntervalMilliseconds;
FOUNDATION_EXPORT NSString* const CentrifugeDefaultPrivateChannelPrefix;
FOUNDATION_EXPORT const int64_t CentrifugeDefaultReadTimeoutMilliseconds;
FOUNDATION_EXPORT const int64_t CentrifugeDefaultWriteTimeoutMilliseconds;

FOUNDATION_EXPORT CentrifugeConfig* CentrifugeDefaultConfig(void);

FOUNDATION_EXPORT NSString* CentrifugeExp(long ttlSeconds);

FOUNDATION_EXPORT NSString* CentrifugeGenerateChannelSign(NSString* secret, NSString* client, NSString* channel, NSString* channelData);

FOUNDATION_EXPORT NSString* CentrifugeGenerateClientSign(NSString* secret, NSString* user, NSString* exp, NSString* info);

FOUNDATION_EXPORT CentrifugeClient* CentrifugeNew(NSString* u, CentrifugeEventHub* events, CentrifugeConfig* config);

FOUNDATION_EXPORT CentrifugeCredentials* CentrifugeNewCredentials(NSString* user, NSString* exp, NSString* info, NSString* sign);

FOUNDATION_EXPORT CentrifugeEventHub* CentrifugeNewEventHub(void);

FOUNDATION_EXPORT CentrifugeSubscriptionEventHub* CentrifugeNewSubscriptionEventHub(void);

@class CentrifugeConnectHandler;

@class CentrifugeDisconnectHandler;

@class CentrifugeErrorHandler;

@class CentrifugeJoinHandler;

@class CentrifugeLeaveHandler;

@class CentrifugeMessageHandler;

@class CentrifugePrivateSubHandler;

@class CentrifugePublishHandler;

@class CentrifugeRefreshHandler;

@class CentrifugeSubscribeErrorHandler;

@class CentrifugeSubscribeSuccessHandler;

@class CentrifugeUnsubscribeHandler;

@interface CentrifugeConnectHandler : NSObject <goSeqRefInterface, CentrifugeConnectHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onConnect:(CentrifugeClient*)p0 p1:(CentrifugeConnectEvent*)p1;
@end

@interface CentrifugeDisconnectHandler : NSObject <goSeqRefInterface, CentrifugeDisconnectHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onDisconnect:(CentrifugeClient*)p0 p1:(CentrifugeDisconnectEvent*)p1;
@end

@interface CentrifugeErrorHandler : NSObject <goSeqRefInterface, CentrifugeErrorHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onError:(CentrifugeClient*)p0 p1:(CentrifugeErrorEvent*)p1;
@end

@interface CentrifugeJoinHandler : NSObject <goSeqRefInterface, CentrifugeJoinHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onJoin:(CentrifugeSubscription*)p0 p1:(CentrifugeJoinEvent*)p1;
@end

@interface CentrifugeLeaveHandler : NSObject <goSeqRefInterface, CentrifugeLeaveHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onLeave:(CentrifugeSubscription*)p0 p1:(CentrifugeLeaveEvent*)p1;
@end

@interface CentrifugeMessageHandler : NSObject <goSeqRefInterface, CentrifugeMessageHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onMessage:(CentrifugeClient*)p0 p1:(CentrifugeMessageEvent*)p1;
@end

@interface CentrifugePrivateSubHandler : NSObject <goSeqRefInterface, CentrifugePrivateSubHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (CentrifugePrivateSign*)onPrivateSub:(CentrifugeClient*)p0 p1:(CentrifugePrivateSubEvent*)p1 error:(NSError**)error;
@end

@interface CentrifugePublishHandler : NSObject <goSeqRefInterface, CentrifugePublishHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onPublish:(CentrifugeSubscription*)p0 p1:(CentrifugePublishEvent*)p1;
@end

@interface CentrifugeRefreshHandler : NSObject <goSeqRefInterface, CentrifugeRefreshHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (CentrifugeCredentials*)onRefresh:(CentrifugeClient*)p0 error:(NSError**)error;
@end

@interface CentrifugeSubscribeErrorHandler : NSObject <goSeqRefInterface, CentrifugeSubscribeErrorHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onSubscribeError:(CentrifugeSubscription*)p0 p1:(CentrifugeSubscribeErrorEvent*)p1;
@end

@interface CentrifugeSubscribeSuccessHandler : NSObject <goSeqRefInterface, CentrifugeSubscribeSuccessHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onSubscribeSuccess:(CentrifugeSubscription*)p0 p1:(CentrifugeSubscribeSuccessEvent*)p1;
@end

@interface CentrifugeUnsubscribeHandler : NSObject <goSeqRefInterface, CentrifugeUnsubscribeHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onUnsubscribe:(CentrifugeSubscription*)p0 p1:(CentrifugeUnsubscribeEvent*)p1;
@end

#endif
