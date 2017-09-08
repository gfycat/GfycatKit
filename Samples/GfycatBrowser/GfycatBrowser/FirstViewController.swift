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
        
        mediaPreview.mediaFormat = .GIF_5MB
        
        let gfycatBrowserSettings = GFYBrowserSettings()
        gfycatBrowserSettings.enableSearchHistory = true
        gfycatBrowserSettings.scrollDirection = .horizontal
        gfycatBrowserSettings.enableRecentItems = true
        gfycatBrowserSettings.categoryMediaFormat = .GIF_2MB
        gfycatBrowserSettings.videoMediaFormat = .GIF_2MB
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
    func gfyMediaView(_ mediaView: GFYMediaView, didStartPlayback media: GfycatMedia) {
        NSLog("Playback started: %@", media.gfyName)
        GFYAnalyticsHub.shared.trackVideoPlayed(withGfyId: media.gfyId, context: .none, keyword: "preview", flow: .half)
        gradientBar.active = false
    }
}
