/******************************************************************************
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Baldur Karlsson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

#ifndef THUMBNAILSTRIP_H
#define THUMBNAILSTRIP_H

#include <QWidget>

namespace Ui
{
class ThumbnailStrip;
}

class ResourcePreview;
class QBoxLayout;

class ThumbnailStrip : public QWidget
{
  Q_OBJECT

public:
  explicit ThumbnailStrip(QWidget *parent = 0);
  ~ThumbnailStrip();

  void AddPreview(ResourcePreview *prev);

  void ClearThumbnails();
  const QVector<ResourcePreview *> &GetThumbs() { return m_Thumbnails; }
  void RefreshLayout();

signals:
  void mouseClick(QMouseEvent *event);

private:
  void resizeEvent(QResizeEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;

  QVector<ResourcePreview *> m_Thumbnails;

  QBoxLayout *layout;

  Ui::ThumbnailStrip *ui;
};

#endif    // THUMBNAILSTRIP_H