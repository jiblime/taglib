/***************************************************************************
    copyright           : (C) 2011 by Mathias Panzenböck
    email               : grosser.meister.morti@gmx.net
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it  under the terms of the GNU Lesser General Public License version  *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,            *
 *   MA  02110-1301  USA                                                   *
 ***************************************************************************/

#ifndef TAGLIB_S3MPROPERTIES_H
#define TAGLIB_S3MPROPERTIES_H

#include "taglib.h"
#include "audioproperties.h"

namespace TagLib {
  namespace S3M {
    class TAGLIB_EXPORT Properties : public AudioProperties {
      friend class File;
    public:
      Properties(AudioProperties::ReadStyle propertiesStyle);
      virtual ~Properties();
      
      int length()     const;
      int bitrate()    const;
      int sampleRate() const;
      int channels()   const;

      ushort tableLength()       const;
      bool   stereo()            const;
      ushort sampleCount()       const;
      ushort patternCount()      const;
      ushort flags()             const;
      ushort trackerVersion()    const;
      ushort fileFormatVersion() const;
      uchar  globalVolume()      const;
      uchar  masterVolume()      const;
      uchar  tempo()             const;
      uchar  bpmSpeed()          const;

    protected:
      void setTableLength(ushort tableLength);
      void setChannels(int channels);

      void setStereo           (bool stereo);
      void setSampleCount      (ushort sampleCount);
      void setPatternCount     (ushort patternCount);
      void setFlags            (ushort flags);
      void setTrackerVersion   (ushort trackerVersion);
      void setFileFormatVersion(ushort fileFormatVersion);
      void setGlobalVolume     (uchar globalVolume);
      void setMasterVolume     (uchar masterVolume);
      void setTempo            (uchar tempo);
      void setBpmSpeed         (uchar bpmSpeed);

    private:
      Properties(const Properties&);
      Properties &operator=(const Properties&);

      class PropertiesPrivate;
      PropertiesPrivate *d;
    };
  }
}

#endif
