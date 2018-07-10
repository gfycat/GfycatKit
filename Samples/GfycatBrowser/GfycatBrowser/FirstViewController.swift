//
//  FirstViewController.swift
//  GfycatBrowser
//
//  Created by Oleksii Chubenko on 4/13/17.
//  Copyright © 2017 Gfycat. All rights reserved.
//

import UIKit
import GfycatKit

class FirstViewController: GFYSimpleContainerViewController {

    @IBOutlet fileprivate var gradientBar: GFYActivityGradientBar!
    @IBOutlet fileprivate var mediaPreview: GFYMediaView!
    @IBOutlet fileprivate var mediaTitle: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        mediaPreview.mediaFormat = .gif5mb
        
        let gfycatBrowserSettings = GFYBrowserSettings()
        gfycatBrowserSettings.enableSearchHistory = true
        // categories browsing settings
        gfycatBrowserSettings.categoryPickerSettings.scrollDirection = .horizontal
        gfycatBrowserSettings.categoryPickerSettings.enableRecentItems = true
        gfycatBrowserSettings.categoryPickerSettings.categoryMediaFormat = .gif2mb
        // media list browsing settings
        gfycatBrowserSettings.mediaPickerSettings.scrollDirection = .horizontal
        gfycatBrowserSettings.mediaPickerSettings.videoMediaFormat = .gif2mb
        
        let browser = GFYBrowserViewController(settings: gfycatBrowserSettings)
        browser.delegate = self
        activeViewController = browser
    }
}

extension FirstViewController: GFYBrowserDelegate {

    func gfycatMediaPicker(_ picker: GFYMediaPickerViewController, didSelect media: GfycatMedia, with source: GFYArraySource) {
        mediaPreview.media = media
        mediaTitle.text = media.title
        gradientBar.active = true
    }
}

extension FirstViewController: GFYMediaViewDelegate {
    
    func gfyMediaView(_ mediaView: GFYMediaView, didStartPlayback media: GfycatReferencedMedia) {
        print("Playback started: \(media.gfyName)")
        GFYAnalyticsHub.shared.trackVideoPlayed(withGfyId: media.gfyId, context: .none, keyword: "preview", flow: .half)
        gradientBar.active = false
    }
}
