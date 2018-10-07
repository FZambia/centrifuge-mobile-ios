//
//  ViewController.swift
//  Centrifuge-iOS
//
//  Created by Alexander Emelin on 07/05/2018.
//  Copyright © 2018 Alexander Emelin. All rights reserved.
//

import UIKit
import Centrifuge

class ConnectHandler : NSObject, CentrifugeConnectHandlerProtocol {
    var l: UILabel!
    
    func setLabel(l: UILabel!) {
        self.l = l
    }
    
    func onConnect(_ p0: CentrifugeClient!, p1: CentrifugeConnectEvent!) {
        DispatchQueue.main.async{
            self.l.text = "Connected with id " + p1.clientID();
        }
    }
}

class DisconnectHandler : NSObject, CentrifugeDisconnectHandlerProtocol {
    var l: UILabel!
    
    func setLabel(l: UILabel!) {
        self.l = l
    }
    
    func onDisconnect(_ p0: CentrifugeClient!, p1: CentrifugeDisconnectEvent!) {
        DispatchQueue.main.async{
            self.l.text = "Disconnected: " + p1.reason();
        }
    }
}

class PublishHandler : NSObject, CentrifugePublishHandlerProtocol {
    var l: UILabel!
    
    func setLabel(l: UILabel!) {
        self.l = l
    }
    
    func onPublish(_ p0: CentrifugeSubscription!, p1: CentrifugePublishEvent!) {
        DispatchQueue.main.async{
            let data = p1.data()
            if let string = String(data: data!, encoding: .utf8) {
                self.l.text = p0.channel() + ":" + string
            } else {
                self.l.text = "error decoding Publication bytes"
            }
        }
    }
}

class ViewController: UIViewController {
    
    @IBOutlet weak var label: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        label.text = "Connecting..."
        
        DispatchQueue.global(qos: .background).async {

            let connectHandler = ConnectHandler()
            connectHandler.setLabel(l: self.label)
            let disconnectHandler = DisconnectHandler()
            disconnectHandler.setLabel(l: self.label)

            let url = "ws://localhost:8000/connection/websocket"
//            let url = "ws://localhost:8000/connection/websocket?format=protobuf"
            
            let client = CentrifugeNew(url, CentrifugeDefaultConfig())
//            client?.setToken("???")
            
            client?.onConnect(connectHandler)
            client?.onDisconnect(disconnectHandler)
            
            do {
                try client?.connect()
            } catch {
                self.label.text = "Error on connect..."
                return
            }

            var sub: CentrifugeSubscription!
            do {
                sub = try client?.newSubscription("chat:index")
            } catch {
                DispatchQueue.main.async{
                    self.label.text = "Subscription create error"
                }
                return
            }
            
            let publishHandler = PublishHandler()
            publishHandler.setLabel(l: self.label)
            sub?.onPublish(publishHandler)
            
            do {
                try sub?.subscribe()
            } catch {
                DispatchQueue.main.async{
                    self.label.text = "Subscribe error"
                }
                return
            }

            DispatchQueue.main.asyncAfter(deadline: .now() + .seconds(3), execute: {
                do {
                    let data = "{\"input\": \"hey there from iOS example!\"}".data(using: .utf8)
                    try sub?.publish(data)
                } catch {
                    self.label.text = "Publish error"
                    return
                }
            })
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

