/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  Weather Routing Plugin
 * Author:   Sean D'Epagnier
 *
 ***************************************************************************
 *   Copyright (C) 2013 by Sean D'Epagnier   *
 *   sean@depagnier.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.             *
 ***************************************************************************
 */

#ifndef _WEATHER_ROUTING_H_
#define _WEATHER_ROUTING_H_


#include <wx/treectrl.h>
#include <wx/fileconf.h>

#include "WeatherRoutingUI.h"
#include "WeatherRoutingConfigurationDialog.h"
#include "WeatherRoutingSettingsDialog.h"

class weather_routing_pi;
class BoatDialog;
class GribUIDialog;

class WeatherRoutingDialog : public WeatherRoutingDialogBase
{
public:
    WeatherRoutingDialog( wxWindow *parent, double boat_lat, double boat_lon );
    ~WeatherRoutingDialog( );

    void Reset();

    void RenderRouteMap(ocpnDC &dc, PlugIn_ViewPort &vp);
    RouteMapOverlay m_RouteMapOverlay;

private:
    void OnUpdateEnd( wxCommandEvent& event );
    void OnCompute( wxCommandEvent& event );
    void OnReset( wxCommandEvent& event );
    void OnSettings( wxCommandEvent& event );
    void OnConfiguration( wxCommandEvent& event );
    void OnBoat( wxCommandEvent& event );
    void OnPlot( wxCommandEvent& event );
    void OnExport( wxCommandEvent& event );
    void OnInformation( wxCommandEvent& event );
    void OnClose( wxCommandEvent& event );
    void OnComputationTimer( wxTimerEvent & );

    void UpdateStatistics();

    void UpdateEnd();
    void Start();
    void Stop();
    void ReconfigureRouteMap();
    void SetRouteMapOverlaySettings();

    //    Data
    weather_routing_pi   *pPlugIn;

    bool m_bComputing;

    bool m_bShowBoatDialog;
    BoatDialog *m_pBoatDialog;

    WeatherRoutingConfigurationDialog m_ConfigurationDialog;
    WeatherRoutingSettingsDialog m_SettingsDialog;

    wxTimer m_tCompute;

    wxTimeSpan m_RunTime;
    wxDateTime m_StartTime;
};

#endif
